/*
** EPITECH PROJECT, 2020
** <Project_name>
** File description:
** t1.c
*/

#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include "nv.h"

static void sig_catch(int sig, siginfo_t *siginfo, void *context)
{
    (void) context;
    (void) siginfo;
    if (sig == SIGUSR1)
        SIG_G.bin_pos[SIG_G.index] = '0';
    else if (sig == SIGUSR2)
        SIG_G.bin_pos[SIG_G.index] = '1';
    SIG_G.index += 1;
}

bool reception_handling(void)
{
    struct sigaction siga_s = {0};

    siga_s.sa_flags = SA_SIGINFO;
    siga_s.sa_sigaction = &sig_catch;
    if (sigaction(SIGUSR1, &siga_s, NULL))
        return (true);
    if (sigaction(SIGUSR2, &siga_s, NULL))
        return (true);
    for (int i = 0 ; i < 8 ; i++)
        pause();
    if (SIG_G.error)
        return (true);
    return (false);
}

int btoi(char *str)
{
    int ret = 0;

    for (int i = 0 , qot = 128 ; str[i] ; i++, qot /= 2)
        if (str[i] == '1')
            ret += qot;
    return (ret);
}

int sig_reception(void)
{
    int ret = 0;

    if (reception_handling())
        return (-1);
    ret = btoi(SIG_G.bin_pos);
    return (ret);
}
