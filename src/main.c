/*
** EPITECH PROJECT, 2020
** Untitled (Workspace)
** File description:
** main
*/

#include "sig.h"

int navy(navy_t *navy, int ac, char **av)
{
    if (map_init(navy, ac, av) || boat_init(navy) || array_init(navy))
        return (84);
    SIG_G.who = SET_HC(ac);
    navy->my_score = 0;
    navy->enm_score = 0;
    navy->enemy_won = 0;
    if (create_connection(av[1]))
        return (84);
    if (game(navy))
        return (84);
    free_all(navy);
    return (navy->enemy_won);
}

int main(int ac, char **av)
{
    navy_t nv;

    if (ac == 1 || (ac == 2 && my_strcmp(av[1], "-h") == 0) ||
        (ac != 2 && ac != 3))
        return (usage(ac));
    return (navy(&nv, ac, av));
}
