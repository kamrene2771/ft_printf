/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_bonus_9.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamrene <kamrene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 10:18:43 by kamrene           #+#    #+#             */
/*   Updated: 2024/12/16 13:09:07 by kamrene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	print_space(int width)
{
	int	returned_len;

	returned_len = 0;
	while (width-- > 0)
		returned_len += ft_putchar(' ');
	return (returned_len);
}

int	width_flags_second(const char *format, va_list args, int *count, int skip)
{
	int	minus;
	int	dot;
	int	r_l;
	int	width;
	int	i;

	(1) && (minus = 0, dot = 0, r_l = 0, width = 0, i = 0);
	while (format[i] && !ft_strchr("cspdiu%xX", format[i]))
	{
		if (format[i] == '-')
			minus++;
		else if (format[i] == '.')
			dot++;
		i++;
	}
	if (minus > 0)
		while (ft_isdigit(*format))
			(1) && (format++, (*count)++);
	else if (dot > 0)
		(1) && (width = dot_num_sec(format, count, args, i) - skip,
			r_l = print_space(width));
	else
		(1) && (width = numbers_else_sec(format, count, args, i) - skip,
			r_l = print_space(width));
	return (r_l);
}

int	dot_numbers_helper_2(int r_l, int argument_l, int width)
{
	if (r_l == 0)
		argument_l--;
	width -= argument_l;
	return (width);
}

int	look_for_first_flag(const char *format)
{
	if (format[0] == '.')
		return (1);
	else if (format[0] == '-')
		return (2);
	else if (format[0] == '0')
		return (3);
	return (0);
}

char	*add_flag(const char *format, int *count, int check)
{
	char	*specifier;

	if (check == 2)
		(1) && (specifier = ft_strjoin("-", format), (*count)--);
	else if (check == 1)
		(1) && (specifier = ft_strjoin(".", format), (*count)--);
	else if (check == 3)
		(1) && (specifier = ft_strjoin("0", format), (*count)--);
	else
		specifier = (char *)format;
	return (specifier);
}
