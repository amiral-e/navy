/*
** EPITECH PROJECT, 2020
** Untitled (Workspace)
** File description:
** errors
*/

#include "nv.h"

int usage(int ac)
{
    if (ac == 2) {
        my_putstr("USAGE\n");
        my_putstr("      ./navy [first_player_pid] navy_positions\n");
        my_putstr("DESCRIPTION\n");
        my_putstr("      first_player_pid: only for the 2nd player.");
        my_putstr(" pid of the first player.\n");
        my_putstr("      navy_positions: file representing the");
        my_putstr(" positions of the ships.\n");
        return (0);
    } else if (ac == 1)
        my_putstr("Usage: ./navy first_player_pid navy_positions\n");
    return (84);
}