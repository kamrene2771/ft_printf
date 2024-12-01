#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <libc.h>
#include "libft/libft.h"



int substr_flags(const char *format,va_list args,int *count);
int ft_printf(const char *format, ...);
int ft_putchar(char c);
int ft_putstr(char *str);
char *ft_itoa_base(unsigned long n, const char *base);
int ft_process_specifier(char specifier, va_list args);
int handle_char(int c);
int handle_str(char *str);
int handle_int(int nbr);
int handle_unsigned(unsigned int nbr);
int handle_hex(unsigned int nbr,char specipier);
int handle_pointer(void *ptr);

#endif