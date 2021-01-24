/*
** EPITECH PROJECT, 2020
** Untitled (Workspace)
** File description:
** getline
*/

#include <stdio.h>
#include "nv.h"

char *my_getline(void)
{
    char *input = NULL;
    size_t len = 0;

    my_putstr("attack: ");
    while (true) {
        if (getline(&input, &len, stdin))
            break;
        my_putstr("\n");
    }
    return (input);
}