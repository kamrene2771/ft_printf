/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_bonus_3.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamrene <kamrene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 17:47:50 by kamrene           #+#    #+#             */
/*   Updated: 2024/12/14 09:24:26 by kamrene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	handle_dot_string(const char *format, va_list args, int *count, int len)
{
	int		how_many;
	char	*specifier_flag_buffer;
	char	*to_print;
	int		c;
	int		second_flag;

	how_many = 0;
	specifier_flag_buffer = ft_substr(format, 1, len);
	second_flag = check(specifier_flag_buffer);
	c = specifier_flag_buffer[second_flag];
	if (check(specifier_flag_buffer) > 0)
		return (handle_both(specifier_flag_buffer, args, count, c));
	how_many = ft_atoi(specifier_flag_buffer);
	*count += ft_strlen(specifier_flag_buffer) + 1;
	free(specifier_flag_buffer);
	to_print = va_arg(args, char *);
	if (!to_print)
		to_print = "(null)";
	to_print = ft_substr(to_print, 0, how_many);
	len = handle_str(to_print);
	free(to_print);
	return (len);
}

int	handle_plus(const char *format, va_list args, int len, int *count)
{
	int	returned_len[2];

	*returned_len = 0;
	returned_len[1] = len;
	if (format[0] == '+' && (format[len] == 'd' || format[len] == 'i'))
		plus_helper(args, format, returned_len, count);
	else if (format[0] == '+')
	{
		if (check((char *)(format)) > 0 || format[1] == '0')
		{
			(*count)++;
			*returned_len += substr_flags(++format, args, count);
		}
		else
		{
			*count += len + 1;
			*returned_len = ft_process_specifier(*(++format), args);
		}
	}
	return (*returned_len);
}

void	plus_helper(va_list args, const char *format, int *r_l, int *count)
{
	int		argument;
	va_list	arglen;

	va_copy(arglen, args);
	argument = va_arg(arglen, int);
	if (argument >= 0 && ft_strchr("-.di", format[1]))
		(1) && (*r_l += ft_putchar('+'), count[1]++);
	if (argument >= 0 && count_flags(format) > 1 && format[1] == '0')
		(1) && (*r_l += ft_putchar('+'));
	if (check((char *)format) > 0)
	{
		if (format[1] == '0' && argument >= 0)
			count[1]++;
		(1) && ((*count)++, *r_l += substr_flags(++format, args, count));
	}
	else if (format[1] == '0' && check((char *)format) == 0)
	{
		if (argument >= 0)
			(1) && (*r_l += ft_putchar('+'), count[1]++);
		(*count)++;
		*r_l += substr_flags(++format, args, count);
	}
	else
		(1) && (*count += r_l[1] + 1, *r_l += ft_process_specifier(*(++format),
				args));
}

void	space_last(int *r_l, int *count, const char *format, va_list args)
{
	int	arg;
	int	len;

	arg = r_l[2];
	len = r_l[3];
	if (arg >= 0)
		*r_l = ft_putchar(' ');
	*count += len + 1;
	*r_l += ft_process_specifier(*(++format), args);
}

int	space_helper(va_list args, const char *format, int len, int *count)
{
	va_list		arglen;
	int			r_l[4];
	int			arg;
	int			i;
	const char	*tmp;

	va_copy(arglen, args);
	(1) && (arg = va_arg(arglen, int), *r_l = 0, i = check((char *)format));
	(1) && (tmp = format + i, r_l[1] = ft_atoi(++tmp), r_l[2] = arg);
	r_l[3] = len;
	if (i > 0)
	{
		if (arg == 0 && format[1] == '0' && r_l[1] == 0)
			*r_l = ft_putchar(' ');
		(1) && ((*count)++, *r_l += substr_flags(++format, args, count));
	}
	else if (format[1] == '0' && i == 0)
	{
		if (arg >= 0)
			(1) && (*r_l = ft_putchar(' '), count[2] = 1);
		(1) && ((*count)++, *r_l += substr_flags(++format, args, count));
	}
	else
		space_last(r_l, count, format, args);
	return (va_end(arglen),*r_l);
}
