/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamrene <kamrene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 15:54:17 by kamrene           #+#    #+#             */
/*   Updated: 2024/12/16 10:28:07 by kamrene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	handle_both(char *specifier_flag_buffer, va_list args, int *count, int c)
{
	int	returned_len;
	int	h1[4];
	int	h2;
	int	specifier;

	(1) && (returned_len = 0, *h1 = 0, h2 = 0, specifier = 0, h1[2] = 0);
	*h1 = ft_atoi(specifier_flag_buffer);
	h2 = ft_atoi(specifier_flag_buffer + check(specifier_flag_buffer) + 1);
	if (specifier_flag_buffer[check(specifier_flag_buffer)] != '.')
		swap(h1, &h2);
	h1[1] = count[1];
	h1[3] = count[2];
	*count += ft_strlen(specifier_flag_buffer) + 1;
	while (specifier_flag_buffer[specifier])
		specifier++;
	if (c == '-' && specifier_flag_buffer[specifier - 1] != 's')
		returned_len = handle_md_all(specifier_flag_buffer, args, h1, h2);
	else if (c == '-')
		returned_len = handle_md_s(args, h1, h2);
	if (c == '0' && specifier_flag_buffer[specifier - 1] != 's')
		returned_len = handle_zd_all(specifier_flag_buffer, args, h1, h2);
	else if (c == '0')
		returned_len = handle_zd_s(args, h1, h2);
	return (returned_len);
}

int	lst_it(char *buffer)
{
	int	s;

	s = 0;
	while (buffer[s])
		s++;
	s = buffer[s - 1];
	return (s);
}

int	handle_md_all(char *buffer, va_list args, int *h1, int h2)
{
	int		lenght;
	int		returned_len;
	int		len;
	int		s;
	va_list	arglen;

	(1) && (lenght = 0, returned_len = 0, len = 0, s = 0);
	va_copy(arglen, args);
	s = lst_it(buffer);
	lenght = zero_dot_flag_lenght(s, arglen, 0, h1);
	if (s == 'p')
		returned_len = ft_putstr("0x");
	if (s == '%')
		h2 = 0;
	va_end(arglen);
	(1) && (returned_len += lenght, len = h2, h2 = h2 - lenght);
	if (h2 > 0)
		while (h2--)
			returned_len += ft_putchar('0');
	returned_len = handle_md_negative(s, args, returned_len, len);
	*h1 = *h1 - returned_len - h1[1] - h1[3];
	if (*h1 > 0)
		while ((*h1)--)
			returned_len += ft_putchar(' ');
	return (returned_len);
}

int	handle_md_negative(char specifier, va_list args, int returned_len, int h2)
{
	va_list	argum;

	va_copy(argum, args);
	if (va_arg(argum, int) == 0 && h2 == 0)
	{
		returned_len--;
		handle_str("\0");
	}
	else if (specifier == 'd' || specifier == 'i')
	{
		returned_len += handle_dot_negative(args);
	}
	else if (specifier == 'p')
		handle_ptr_zero(args);
	else
		ft_process_specifier(specifier, args);
	return (va_end(argum), returned_len);
}

int	handle_md_s(va_list args, int *h1, int h2)
{
	char	*to_print;
	int		returned_len;

	to_print = va_arg(args, char *);
	if (!to_print)
		to_print = "(null)";
	to_print = ft_substr(to_print, 0, h2);
	returned_len = handle_str(to_print);
	*h1 = *h1 - returned_len;
	if (*h1 > 0)
		while ((*h1)--)
			returned_len += ft_putchar(' ');
	free(to_print);
	return (returned_len);
}
