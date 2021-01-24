/*
** EPITECH PROJECT, 2020
** Untitled (Workspace)
** File description:
** check
*/

#include "nv.h"

int check_input(char *input, navy_t *navy)
{
    if (!input || my_strlen(input) != 3)
        return (1);
    if ((input[0] < 'A' || input[0] > 'H') ||
        (input[1] < '1' || input[1] > '8'))
        return (1);
    if (navy->enm_arr[input[1] - '1'][input[0] - 'A'] == 'x' ||
        navy->enm_arr[input[1] - '1'][input[0] - 'A'] == 'o')
        return (1);
    return (0);
}