/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamrene <kamrene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 16:12:31 by kamrene           #+#    #+#             */
/*   Updated: 2024/12/16 13:11:08 by kamrene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	dot_numbers(const char *format, int *count, va_list args, int i)
{
	int		width;
	int		r_l;
	int		argument_l;
	va_list	argum;
	va_list	arglen;

	va_copy(argum, args);
	va_copy(arglen, args);
	(1) && (r_l = va_arg(argum, int), width = ft_atoi(format));
	while (ft_isdigit(*format))
		(1) && (format++, (*count)++, i--);
	argument_l = calculate_lenght(format[i], arglen);
	if (format[i] == 's' && argument_l < ft_atoi(format + 1))
		width -= argument_l;
	else if ((format[i] != 's') && r_l < 0 && width > ft_atoi(format + 1))
		width = dot_numbers_helper(format, argument_l, width, i);
	else if (argument_l > ft_atoi(format + 1) && (format[i] != 's'))
		width = dot_numbers_helper_2(r_l, argument_l, width);
	else
		width -= ft_atoi((format + 1));
	r_l = 0;
	while (width > 0)
		(1) && (width--, r_l += ft_putchar(' '));
	r_l += substr_flags(format, args, count);
	return (r_l);
}

int	numbers_else(const char *format, int *count, va_list args, int i)
{
	int		width;
	va_list	arglen;
	int		returned_len;

	returned_len = 0;
	va_copy(arglen, args);
	if (format[0] == '*')
	{
		width = va_arg(args, int);
		width -= calculate_lenght(format[i], arglen);
	}
	else
		width = ft_atoi(format) - calculate_lenght(format[i], arglen);
	if (format[i] == 'p')
		width -= 2;
	while (width > 0)
		(1) && (width--, returned_len += ft_putchar(' '));
	while (ft_isdigit(*format) || *format == '*')
		(1) && (format++, (*count)++);
	returned_len += ft_process_specifier(*format, args);
	(*count)++;
	return (returned_len);
}

int	width_flags(const char *format, va_list args, int *count)
{
	int	minus;
	int	dot;
	int	returned_len;
	int	width;
	int	i;

	(1) && (minus = 0, dot = 0, returned_len = 0);
	width = 0;
	i = 0;
	while (format[i] && !ft_strchr("cspdiu%xX", format[i]))
	{
		if (format[i] == '-')
			minus++;
		else if (format[i] == '.')
			dot++;
		i++;
	}
	if (minus > 0)
		returned_len = minus_numbers(format, count, args);
	else if (dot > 0)
		returned_len = dot_numbers(format, count, args, i);
	else
		returned_len = numbers_else(format, count, args, i);
	return (returned_len);
}

int	printf_helper(const char *format, va_list args, int *len, int count)
{
	int	check;
	int	check_first;

	check_first = look_for_first_flag(format);
	check = look_for_all(format);
	if (check == 1)
		count += sharp_search(format, args, len, check_first);
	else if (check == 2)
		count += plus_search(format, args, len, check_first);
	else if (check == 3)
		count += space_search(format, args, len, check_first);
	else
		count += substr_flags(format, args, len);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;
	int		len[3];

	count = 0;
	va_start(args, format);
	while (*format)
	{
		(1) && (len[0] = 0, len[1] = 0, len[2] = 0);
		if (*format == '%' && ft_strchr("-0.# +", *(format + 1)))
			(1) && (count = printf_helper(++format, args, len, count), format
				+= len[0]);
		else if (*format == '%' && (ft_isdigit(*(format + 1)) || *(format
					+ 1) == '*'))
		{
			count += width_flags(++format, args, len);
			format += len[0];
		}
		else if (*format == '%' && *(++format))
			count += ft_process_specifier(*format++, args);
		else
			count += ft_putchar(*format++);
	}
	va_end(args);
	return (count);
}
