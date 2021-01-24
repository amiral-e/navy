/*
** EPITECH PROJECT, 2020
** Untitled (Workspace)
** File description:
** attack
*/

#include <stdlib.h>
#include "nv.h"

void attack_from_enm(navy_t *nv, int y, int x)
{
    if (nv->my_arr[x - 1][y - 1] == '.')
        nv->my_arr[x - 1][y - 1] = 'o';
    else {
        nv->my_arr[x - 1][y - 1] = 'x';
        nv->enm_score++;
    }
}

void attack_from_my(navy_t *nv, int y, int x, int ret)
{
    if (ret != 99)
        nv->enm_arr[x - 1][y - 1] = 'o';
    else {
        nv->enm_arr[x - 1][y - 1] = 'x';
        nv->my_score++;
    }
}

int attack(navy_t *navy)
{
    char *input = my_getline();
    int nb = -1;

    if (check_input(input, navy))
        while (check_input(input, navy)) {
            my_putstr("wrong position\n");
            input = my_getline();
        }
    input[2] = '\0';
    if (sig_sending(input, SIG_G.enm_pid))
        return (1);
    nb = sig_reception();
    if (nb == 99)
        my_printf("%s: hit\n\n", input);
    else
        my_printf("%s: missed\n\n", input);
    attack_from_my(navy, input[0] - '@', input[1] - '0', nb);
    free(input);
    return (0);
}

int defend(navy_t *navy)
{
    int nb = -1;

    my_putstr("waiting for enemy's attack...\n");
    nb = sig_reception();
    usleep(10000);
    if (check_hit(navy, nb / 10, nb % 10) &&
        !sig_sending("I9", SIG_G.enm_pid))
        my_printf("%c%c: hit\n\n", nb / 10 + '@', ITOC(nb % 10));
    else if (!check_hit(navy, nb / 10, nb % 10) &&
        !sig_sending("@0", SIG_G.enm_pid))
        my_printf("%c%c: missed\n\n", nb / 10 + '@', ITOC(nb % 10));
    else
        return (1);
    attack_from_enm(navy, nb / 10, nb % 10);
    return (0);
}