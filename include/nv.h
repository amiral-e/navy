/*
** EPITECH PROJECT, 2020
** Untitled (Workspace)
** File description:
** ls.h
*/

#ifndef NV_H
#define NV_H

#include "../lib/include/m_files.h"
#include "../lib/include/m_macro.h"
#include <stdbool.h>

typedef struct map_s
{
    char *buffer;
    int size;
    int fd;
} map_t;

typedef struct boat_s
{
    int *size;
    int **pos_b;
    int **pos_e;
} boat_t;

typedef struct navy_s
{
    map_t map;
    boat_t boat;
    int enemy_won;
    int my_score;
    int enm_score;
    char **my_arr;
    char **enm_arr;
} navy_t;

typedef struct sighan_s {
    char bin_pos[9];
    int index;
    bool error;
    enum {HOST, CLIENT} who;
    pid_t my_pid;
    pid_t enm_pid;
} sighan_t;

#define REV_HC(value) ((value == HOST) ? CLIENT : HOST)
#define SET_HC(ac) ((ac == 3) ? CLIENT : HOST)

extern sighan_t SIG_G;

int check_hit(navy_t *navy, int x, int y);
int attack(navy_t *navy);
int defend(navy_t *navy);

int check_input(char *input, navy_t *navy);
char *my_getline(void);

int game(navy_t *navy);

int sboats_check(navy_t *nv);
int rboats_check(navy_t *nv, int pos);
int boat_init(navy_t *nv);

int limit_exceeded(navy_t *nv, int pos);
int map_init(navy_t *nv, int ac, char **av);
int array_init(navy_t *nv);

void print_game(navy_t *navy);
int usage(int ac);

bool create_connection(char *enm_pid);
bool sig_sending(char const *input, pid_t pid);
int sig_reception(void);

void free_all(navy_t *nv);

#endif
