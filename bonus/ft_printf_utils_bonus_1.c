/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_bonus_1.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamrene <kamrene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 17:40:10 by kamrene           #+#    #+#             */
/*   Updated: 2024/12/15 17:54:53 by kamrene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	zd_all_helper(int c, int *h1, int argument, int h2)
{
	if (h1[1] == 0 && argument < 0 && (c == 'd' || c == 'i'))
		*h1 -= h2 + h1[1] + h1[3] + 1;
	else
		*h1 -= h2 + h1[1] + h1[3];
}

int	zd_all_helper2(int c, int *h1, int returned_len, int h2)
{
	if ((c == 'd' || c == 'i') && h1[1] == 1)
		h1[2] = 1;
	if (c == 'X')
		h1[1]++;
	h2 -= returned_len;
	return (h2);
}

int	zd_all_helper3(int c, int *h1, int returned_len, int h2)
{
	if (c == 'p' && h2 > 0)
		ft_putstr("0x");
	else if (c == 'p')
		(1) && (*h1 -= 2, returned_len += 2);
	return (returned_len);
}

int	zd_all_print(int *arg, int h2, int specifier, va_list args)
{
	if (*arg == 0 && specifier == 0)
		(1) && (va_arg(args, int), handle_str(" \0"));
	else if (arg[1] == 'd' || arg[1] == 'i')
		handle_dot_negative(args);
	else if (arg[1] == 'p' && h2 > 0)
		(1) && (handle_ptr_zero(args), arg[2] += 2);
	else
		ft_process_specifier(arg[1], args);
	return (arg[2]);
}

int	handle_zd_all(char *bf, va_list args, int *h1, int h2)
{
	int		returned_len;
	int		specifier;
	va_list	arglen;
	va_list	argum;
	int		arg[4];

	(1) && (returned_len = 0, specifier = 0, *arg = 0);
	va_copy(arglen, args);
	va_copy(argum, args);
	(1) && (*arg = va_arg(argum, int), arg[1] = lst_it(bf));
	returned_len = zero_dot_flag_lenght(arg[1], arglen, 1, h1);
	(1) && (specifier = h2, arg[3] = *h1);
	if (h2 < returned_len)
		h2 = returned_len;
	zd_all_helper(arg[1], h1, *arg, h2);
	h2 = zd_all_helper2(arg[1], h1, returned_len, h2);
	returned_len = zd_all_helper3(arg[1], h1, returned_len, h2);
	if (arg[1] == '%')
		(1) && (h2 = arg[3] - 1, *h1 = 0);
	returned_len += handle_zd_negative(args, h1, h2);
	arg[2] = returned_len;
	returned_len = zd_all_print(arg, h2, specifier, args);
	va_end(argum);
	va_end(arglen);
	return (returned_len);
}
