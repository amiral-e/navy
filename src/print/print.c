/*
** EPITECH PROJECT, 2020
** Untitled (Workspace)
** File description:
** print
*/

#include "nv.h"

void print_array(char **arr)
{
    my_putstr(" |A B C D E F G H\n-+---------------\n");
    for (int i = 0; i < 8; i++) {
        my_printf("%d|", i + 1);
        for (int j = 0; j < 8; j++) {
            my_putchar(arr[i][j]);
            if (arr[i][j + 1])
                my_putchar(' ');
        }
        my_putchar('\n');
    }
    my_putchar('\n');
}

void print_game(navy_t *navy)
{
    my_putstr("my positions:\n");
    print_array(navy->my_arr);
    my_putstr("enemy's positions:\n");
    print_array(navy->enm_arr);
}