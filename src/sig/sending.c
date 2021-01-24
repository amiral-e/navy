/*
** EPITECH PROJECT, 2020
** <Project_name>
** File description:
** t2.c
*/

#include <stdbool.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

bool send(char sig, pid_t pid)
{
    if (sig == '0' && kill(pid, SIGUSR1))
        return (true);
    else if (sig == '1' && kill(pid, SIGUSR2))
        return (true);
    return (false);
}

bool sending_loop(char *binary, pid_t pid)
{
    for (int i = 0 ; i < 8 ; i++) {
        if (send(binary[i], pid))
            return (true);
        usleep(5000);
    }
    free(binary);
    return (false);
}

int pos_to_dec(char const *str)
{
    int result = 0;

    result = str[0] - '@';
    result *= 10;
    result += str[1] - '0';
    return (result);
}

char *itob(int nbr)
{
    char *str = malloc(sizeof(char) * 9);

    if (str == NULL)
        return (NULL);
    for (int i = 0 ; i < 8 ; i++)
        str[i] = '0';
    for (int i = 7 ; nbr > 0 ; i--, nbr /= 2)
        str[i] = (nbr % 2) + '0';
    return (str);
}

bool sig_sending(char const *input, pid_t pid)
{
    int dec_input = pos_to_dec(input);
    char *bin_input = NULL;

    if (dec_input == -1)
        return (true);
    bin_input = itob(dec_input);
    if (bin_input == NULL)
        return (true);
    return (sending_loop(bin_input, pid));
}
