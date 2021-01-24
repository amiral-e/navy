/*
** EPITECH PROJECT, 2020
** Untitled (Workspace)
** File description:
** main.c
*/

#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include "m_printf.h"

int check_flag_id(char f)
{
    char *fi_tab = "scdioSuxXpnb%-0+#";

    for (int i = 0; fi_tab[i]; i++)
        if (f == fi_tab[i])
            return (1);
    return (0);
}

void call_flag(va_list list, int f)
{
    void (*fp[128]) (va_list list);

    fp['s'] = &pf_str;
    fp['c'] = &pf_c;
    fp['d'] = &pf_di;
    fp['i'] = &pf_di;
    fp['o'] = &pf_oct;
    fp['S'] = &pf_sfm;
    fp['u'] = &pf_u;
    fp['x'] = &pf_hexa;
    fp['X'] = &pf_hexam;
    fp['p'] = &pf_adress;
    fp['b'] = &pf_bin;
    fp['%'] = &pf_prc;
    fp[f](list);
}

void ash_f(char c)
{
    switch (c) {
        case 'o':
            my_putchar('0');
            break;
        case 'x':
            my_putstr("0x");
            break;
        case 'X':
            my_putstr("0X");
            break;
    }
}

int man_flag_id(va_list list, const char *format, int i)
{
    for (; format[i] && check_flag_id(format[i]); i++) {
        if (format[i] == '#')
            ash_f(format[i + 1]);
        if (format[i - 1] == '#')
            call_flag(list, format[i]);
    }
    return (i - 1);
}

int my_printf(const char *format, ...)
{
    va_list list;

    va_start(list, format);
    for (int i = 0; format[i]; i++) {
        if (format[i] == '%' && check_flag_id(format[i + 1]))
            if (format[i + 1] == 'n')
                pf_n(list, (i++ + 1));
            else if (format[i] == '#')
                i = man_flag_id(list, format, i);
            else
                call_flag(list, format[i++ + 1]);
        else
            my_putchar(format[i]);
    }
    va_end(list);
    return (0);
}