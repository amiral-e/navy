/*
** EPITECH PROJECT, 2020
** Untitled (Workspace)
** File description:
** free
*/

#include <stdlib.h>
#include "nv.h"

void free_all(navy_t *nv)
{
    for (int i = 0; i < 4; i++)
        free(nv->my_arr[i]);
    free(nv->my_arr);
    free(nv->boat.size);
    for (int i = 0; i < 4; i++) {
        free(nv->boat.pos_b[i]);
        free(nv->boat.pos_e[i]);
    }
    free(nv->boat.pos_b);
    free(nv->boat.pos_e);
}