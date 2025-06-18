/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_bonus_5.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamrene <kamrene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 17:42:16 by kamrene           #+#    #+#             */
/*   Updated: 2024/12/14 22:24:32 by kamrene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	handle_zd_negative(va_list args, int *h1, int h2)
{
	va_list	argcheck;
	int		returned_len;
	int		flag;

	returned_len = 0;
	flag = 0;
	va_copy(argcheck, args);
	if (va_arg(argcheck, int) < 0 && h1[2] == 1)
		flag = 1;
	if (*h1 > 0)
		while ((*h1)--)
			returned_len += ft_putchar(' ');
	if (h1[2] == 1 && flag == 0)
		returned_len += ft_putchar('+');
	if (h1[1] == 2)
		returned_len += ft_putstr("0x");
	else if (h1[1] == 3)
		returned_len += ft_putstr("0X");
	if (flag == 1)
		returned_len += ft_putchar('-');
	va_end(argcheck);
	if (h2 > 0)
		while (h2--)
			returned_len += ft_putchar('0');
	return (returned_len);
}

int	handle_zd_s(va_list args, int *h1, int h2)
{
	int		returned_len;
	char	*to_print;
	va_list	arglen;

	returned_len = 0;
	va_copy(arglen, args);
	to_print = va_arg(arglen, char *);
	if (!to_print)
		to_print = "(null)";
	returned_len = ft_strlen(ft_substr(to_print, 0, h2));
	if (h2 == 0)
		returned_len = 0;
	*h1 -= returned_len;
	if (*h1 > 0)
		while ((*h1)--)
			returned_len += ft_putchar('0');
	to_print = va_arg(args, char *);
	if (!to_print)
		to_print = "(null)";
	to_print = ft_substr(to_print, 0, h2);
	handle_str(to_print);
	free(to_print);
	va_end(arglen);
	return (returned_len);
}

int	print_zero(int *how_many, char *format, va_list args, int len)
{
	int		returned_len;
	int		lenght;
	va_list	arglen;
	va_list	argum;
	int		h2;

	va_copy(arglen, args);
	va_copy(argum, args);
	lenght = zero_flag_lenght(format[len], arglen);
	(1) && (returned_len = *how_many - how_many[1], h2 = *how_many);
	lenght = print_zero_helper(format[len], lenght, how_many);
	if (*how_many > 0)
		while ((*how_many)--)
			ft_putchar('0');
	else
		returned_len = lenght;
	if (format[len] == 'p')
		handle_ptr_zero(args);
	else if (format[len] == 'd' || format[len] == 'i')
		handle_zero_negative(args);
	else
		ft_process_specifier(format[len], args);
	return (va_end(arglen), va_end(argum), returned_len);
}

int	handle_space(const char *format, va_list args, int len, int *count)
{
	va_list	arglen;
	int		r_l;
	int		arg;
	int		i;

	va_copy(arglen, args);
	(1) && (arg = va_arg(arglen, int), r_l = 0, i = check((char *)format));
	if ((format[0] == ' ') && (format[len] == 'd' || format[len] == 'i'))
	{
		if (arg >= 0 && (format[1] == '.' || format[1] == '-'))
			(1) && (r_l = ft_putchar(' '), count[2] = 1);
		if (arg >= 0 && count_flags(format) > 1 && format[1] == '0')
			(1) && (r_l = ft_putchar(' '), count[2] = 1);
		r_l += space_helper(args, format, len, count);
	}
	else if (format[0] == ' ')
	{
		if (i > 0 || format[1] == '0')
			(1) && ((*count)++, r_l += substr_flags(++format, args, count));
		else
			(1) && (*count += len + 1, r_l = ft_process_specifier(*(++format),
					args));
	}
	va_end(arglen);
	return (r_l);
}

int	handle_sharp(const char *format, va_list args, int len, int *count)
{
	va_list	arglen;
	int		returned_len[3];
	int		argument;
	int		i;

	va_copy(arglen, args);
	(1) && (*returned_len = 0, returned_len[1] = len);
	i = check((char *)(format));
	(1) && (returned_len[2] = i, argument = va_arg(arglen, int));
	if ((format[0] == '#') && (format[len] == 'x' || format[len] == 'X'))
	{
		if (argument != 0 && ft_strchr(".-xX", format[1]))
			(1) && (*returned_len = ft_putchar('0'), *returned_len
				+= ft_putchar(format[len]));
		if (argument != 0 && count_flags(format) > 1 && format[1] == '0')
			(1) && (*returned_len = ft_putchar('0'), *returned_len
				+= ft_putchar(format[len]));
		va_end(arglen);
		sharp_helper(format, returned_len, count, args);
	}
	else if (format[0] == '#')
		sharp_all(returned_len, format, count, args);
	return (*returned_len);
}
