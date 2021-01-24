/*
** EPITECH PROJECT, 2020
** Untitled (Workspace)
** File description:
** base.c
*/

#include "m_printf.h"

void pf_bin(va_list list)
{
    my_put_nbr_bin(va_arg(list, int));
}

void pf_oct(va_list list)
{
    my_put_nbr(my_itooct(va_arg(list, unsigned int)));
}

void pf_hexa(va_list list)
{
    my_put_nbr_unhex((unsigned int)va_arg(list, int), false, 0);
}

void pf_hexam(va_list list)
{
    int nb = va_arg(list, int);

    if (nb < 0)
        my_put_nbr_unhex((unsigned int)nb, true, 1);
    else
        my_put_nbr_unhex((unsigned int)nb, true, 0);
}