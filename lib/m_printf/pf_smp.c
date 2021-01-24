/*
** EPITECH PROJECT, 2020
** Untitled (Workspace)
** File description:
** pf_simple.c
*/

#include "m_printf.h"

void pf_n(va_list list, int i)
{
    int *nb = va_arg(list, int *);
    *nb = (i - 1);
}

void pf_adress(va_list list)
{
    unsigned int nb = (unsigned int)va_arg(list, int);

    if (nb == 0 || !nb)
        my_putstr("(nil)");
    else {
        my_putstr("0x");
        my_put_nbr_unhex(nb, false, 0);
    }
}

void pf_sfm_oct(int c)
{
    int oct = my_itooct(c);
    int i = 1;

    my_putchar('\\');
    for (int tmp = oct; tmp; tmp /= 10, i++);
    for (int j = 0; j <= (3 - i); j++)
        my_putchar('0');
    my_put_nbr(oct);
}

void pf_sfm(va_list list)
{
    char *str = va_arg(list, char *);

    for (int i = 0 ; str[i] ; i++ ) {
        if (str[i] >= 32 && str[i] <= 126)
            my_putchar(str[i]);
        else
            pf_sfm_oct(str[i]);
    }
}