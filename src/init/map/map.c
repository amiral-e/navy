/*
** EPITECH PROJECT, 2020
** Untitled (Workspace)
** File description:
** map
*/

#include <fcntl.h>
#include <stdlib.h>
#include "nv.h"

static int fill_my_arr_b(navy_t *nv, int pos)
{
    for (int i = nv->boat.pos_b[pos][1]; i <= nv->boat.pos_e[pos][1]; i++) {
        if (nv->my_arr[nv->boat.pos_b[pos][0]][i] != '.')
            return (1);
        nv->my_arr[nv->boat.pos_b[pos][0]][i] = nv->boat.size[pos] + '0';
    }
    return (0);
}

static int fill_my_arr(navy_t *nv, int pos)
{
    if (limit_exceeded(nv, pos))
        return (1);
    if (nv->boat.pos_b[pos][1] != nv->boat.pos_e[pos][1])
        return (fill_my_arr_b(nv, pos));
    for (int i = nv->boat.pos_b[pos][0]; i <= nv->boat.pos_e[pos][0]; i++) {
        if (nv->my_arr[i][nv->boat.pos_b[pos][1]] != '.')
            return (1);
        nv->my_arr[i][nv->boat.pos_b[pos][1]] = nv->boat.size[pos] + '0';
    }
    return (0);
}

static void create_arrays(navy_t *nv)
{
    nv->my_arr = malloc(sizeof(char *) * 9);
    nv->enm_arr = malloc(sizeof(char *) * 9);
    for (int i = 0; i < 8; i++) {
        nv->my_arr[i] = malloc(sizeof(char) * 9);
        nv->enm_arr[i] = malloc(sizeof(char) * 9);
        for (int j = 0; j < 8; j++) {
            nv->my_arr[i][j] = '.';
            nv->enm_arr[i][j] = '.';
        }
        nv->my_arr[i][8] = '\0';
        nv->enm_arr[i][8] = '\0';
    }
    nv->my_arr[8] = '\0';
    nv->enm_arr[8] = '\0';
}

int array_init(navy_t *nv)
{
    create_arrays(nv);
    for (int i = 0; i < 4; i++)
        if (fill_my_arr(nv, i))
            return (1);
    free(nv->map.buffer);
    return (0);
}

int map_init(navy_t *nv, int ac, char **av)
{
    char *map;

    if (ac == 2)
        map = my_strdup(av[1]);
    else if (ac == 3)
        map = my_strdup(av[2]);
    nv->map.fd = open(map, O_RDONLY);
    if (nv->map.fd == -1)
        return (1);
    nv->map.buffer = malloc(sizeof(char) * 33);
    nv->map.size = read(nv->map.fd, nv->map.buffer, 32);
    nv->map.buffer[32] = '\0';
    if (my_strlen(nv->map.buffer) != 32)
        return (1);
    close(nv->map.fd);
    return (0);
}