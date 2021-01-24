/*
** EPITECH PROJECT, 2020
** Untitled (Workspace)
** File description:
** game
*/

#include "nv.h"

int end_game(navy_t *navy)
{
    if (navy->my_score != 14 && navy->enm_score != 14)
        return (0);
    print_game(navy);
    my_putstr((navy->my_score == 14) ? "I won\n" : "Enemy won\n");
    return (1);
}

int game(navy_t *navy)
{
    for (int i = 0; !end_game(navy); i++) {
        if (i % 2 == 0)
            print_game(navy);
        if (SIG_G.who == HOST && attack(navy))
            return (1);
        else if (SIG_G.who == CLIENT && defend(navy))
            return (1);
        SIG_G.who = REV_HC(SIG_G.who);
        SIG_G.index = 0;
    }
    if (navy->enm_score == 14)
        navy->enemy_won = 1;
    return (0);
}