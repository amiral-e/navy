/*
** EPITECH PROJECT, 2020
** Untitled (Workspace)
** File description:
** connection
*/

#include <signal.h>
#include "nv.h"

static void fst_catch(int sig, siginfo_t *siginfo, void *context)
{
    (void) sig;
    (void) context;
    if (SIG_G.enm_pid == 0)
        SIG_G.enm_pid = siginfo->si_pid;
    else if (SIG_G.enm_pid != siginfo->si_pid)
        SIG_G.error = true;
    if (siginfo->si_signo == SIGUSR1)
        return;
    if (siginfo->si_signo == SIGUSR2)
        return;
}

static bool fst_contact_receive(void)
{
    struct sigaction siga_s = {0};

    siga_s.sa_flags = SA_SIGINFO;
    siga_s.sa_sigaction = &fst_catch;
    if (sigaction(SIGUSR1, &siga_s, NULL))
        return (true);
    if (sigaction(SIGUSR2, &siga_s, NULL))
        return (true);
    pause();
    return (false);
}

bool create_connection(char *enm_pid)
{
    SIG_G.my_pid = getpid();
    if (SIG_G.who == CLIENT) {
        SIG_G.enm_pid = my_atoi(enm_pid);
        if (kill(SIG_G.enm_pid, SIGUSR1))
            return (true);
        else if (fst_contact_receive())
            return (true);
        my_printf("my_pid: %d\n", SIG_G.my_pid);
        my_putstr("successfully connected\n\n");
    } else {
        my_printf("my_pid: %d\n", SIG_G.my_pid);
        my_putstr("waiting for enemy connection...\n");
        if (fst_contact_receive())
            return (true);
        else if (kill(SIG_G.enm_pid, SIGUSR1))
            return (true);
        my_putstr("\nenemy connected\n\n");
    }
    return (false);
}