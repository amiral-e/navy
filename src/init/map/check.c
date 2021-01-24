/*
** EPITECH PROJECT, 2020
** Untitled (Workspace)
** File description:
** check_m
*/

#include "nv.h"

int limit_exceeded(navy_t *nv, int pos)
{
    for (int i = 0; i < 2; i++) {
        if (nv->boat.pos_b[pos][i] < 0 ||
            nv->boat.pos_b[pos][i] > 7)
            return (1);
        else if (nv->boat.pos_e[pos][i] < 0 ||
            nv->boat.pos_e[pos][i] > 7)
            return (1);
    }
    return (0);
}