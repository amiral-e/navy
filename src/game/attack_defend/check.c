/*
** EPITECH PROJECT, 2020
** Untitled (Workspace)
** File description:
** a_check
*/

#include "nv.h"

int check_hit(navy_t *navy, int x, int y)
{
    return (navy->my_arr[y - 1][x - 1] != '.') ? 1 : 0;
}