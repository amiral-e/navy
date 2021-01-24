/*
** EPITECH PROJECT, 2020
** Untitled (Workspace)
** File description:
** check_b
*/

#include "nv.h"

int rboats_check(navy_t *nv, int pos)
{
    int count = 1;
    int p = 0;

    if ((nv->boat.pos_b[pos][0] != nv->boat.pos_e[pos][0]) &&
        (nv->boat.pos_b[pos][1] != nv->boat.pos_e[pos][1]))
        return (1);
    else if (nv->boat.pos_b[pos][1] != nv->boat.pos_e[pos][1])
        p++;
    for (int i = nv->boat.pos_b[pos][p]; i < nv->boat.pos_e[pos][p];
        count++, i++);
    return ((count != nv->boat.size[pos]) ? 1 : 0);
}

int sboats_check(navy_t *nv)
{
    int size = 2;

    for (int i = 0; nv->boat.size[i]; size++, i++)
        if (nv->boat.size[i] != size)
            return (1);
    return (0);
}