/*
** EPITECH PROJECT, 2020
** Untitled (Workspace)
** File description:
** boats
*/

#include <stdlib.h>
#include "nv.h"

void boats_fill(navy_t *nv)
{
    int pos = 0;

    nv->boat.size = malloc(sizeof(int) * 5);
    nv->boat.pos_b = malloc(sizeof(int *) * 5);
    nv->boat.pos_e = malloc(sizeof(int *) * 5);
    for (int i = 0; i < 4; pos += 8, i++) {
        nv->boat.size[i] = nv->map.buffer[pos] - '0';
        nv->boat.pos_b[i] = malloc(sizeof(int) * 2);
        nv->boat.pos_e[i] = malloc(sizeof(int) * 2);
        nv->boat.pos_b[i][0] = nv->map.buffer[pos + 2] - 'A';
        nv->boat.pos_b[i][1] = nv->map.buffer[pos + 3] - '0' - 1;
        nv->boat.pos_e[i][0] = nv->map.buffer[pos + 5] - 'A';
        nv->boat.pos_e[i][1] = nv->map.buffer[pos + 6] - '0' - 1;
    }
    nv->boat.size[4] = '\0';
    nv->boat.pos_b[4] = '\0';
    nv->boat.pos_e[4] = '\0';
}

int boat_init(navy_t *nv)
{
    boats_fill(nv);
    if (sboats_check(nv))
        return (1);
    for (int i = 0; i < 4; i++)
        if (rboats_check(nv, i))
            return (1);
    return (0);
}