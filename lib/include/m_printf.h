/*
** EPITECH PROJECT, 2020
** Untitled (Workspace)
** File description:
** m_printf.h
*/

#ifndef M_PRINTF_H
#define M_PRINTF_H

#include "m_files.h"
#include <stdbool.h>
#include <stddef.h>
#include <stdarg.h>

void pf_str(va_list list);
void pf_c(va_list list);
void pf_di(va_list list);
void pf_oct(va_list list);
void pf_sfm(va_list list);
void pf_u(va_list list);
void pf_prc(va_list list);
void pf_hexa(va_list list);
void pf_hexam(va_list list);
void pf_adress(va_list list);
void pf_bin(va_list list);
void pf_n(va_list list, int i);

#endif /* M_PRINTF_H */