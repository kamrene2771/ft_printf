/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_bonus_8.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamrene <kamrene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 10:18:50 by kamrene           #+#    #+#             */
/*   Updated: 2024/12/16 12:59:13 by kamrene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	minus_numbers(const char *format, int *count, va_list args)
{
	int		width;
	char	*tmp;
	char	*substr;
	int		returned_len;

	(1) && (tmp = NULL, substr = NULL, width = ft_atoi(format));
	while (ft_isdigit(*format))
		(1) && (format++, (*count)++);
	if (ft_atoi(format + 1) == 0)
	{
		if (*(format + 1) == '0')
			(*count) += 2;
		(*count)--;
		while (!ft_strchr("cspdiuxX%", *format))
			(1) && (format++, (*count)--);
		tmp = ft_itoa((long)width);
		substr = ft_strjoin((const char *)tmp, format);
		(1) && (free(tmp), tmp = substr, substr = ft_strjoin("-", substr));
		free(tmp);
		returned_len = substr_flags((const char *)substr, args, count);
		free(substr);
	}
	else
		returned_len = substr_flags(format, args, count);
	return (returned_len);
}

int	dot_numbers_helper(const char *format, int argument_l, int width, int i)
{
	int	save;

	if (format[i] == 'u' && argument_l <= ft_atoi(format + 1))
		width += 1;
	if ((format[i] == 'x' || format[i] == 'X') && ft_atoi(format
			+ 1) >= argument_l)
		width += 1;
	if (argument_l > ft_atoi(format + 1))
		width -= argument_l;
	else if (argument_l < ft_atoi(format + 1))
	{
		save = argument_l - 1;
		argument_l = ft_atoi(format + 1) + argument_l;
		width -= argument_l - save;
	}
	else if (argument_l == ft_atoi(format + 1))
	{
		argument_l--;
		argument_l = ft_atoi(format + 1) - argument_l;
		width -= argument_l + ft_atoi(format + 1);
	}
	else
		width -= ft_atoi((format + 1));
	return (width);
}

int	dot_numbers_helper_sec(const char *format, int argument_l, int width, int i)
{
	int	save;

	if (format[i] == 'u' && argument_l <= ft_atoi(format + 1))
		width += 1;
	if ((format[i] == 'x' || format[i] == 'X') && ft_atoi(format
			+ 1) >= argument_l)
		width += 1;
	if (argument_l > ft_atoi(format + 1))
		width -= argument_l;
	else if (argument_l < ft_atoi(format + 1))
	{
		save = argument_l - 1;
		argument_l = ft_atoi(format + 1) + argument_l;
		width -= argument_l - save;
	}
	else if (argument_l == ft_atoi(format + 1))
	{
		argument_l--;
		argument_l = ft_atoi(format + 1) - argument_l;
		width -= argument_l + ft_atoi(format + 1);
	}
	else
		width -= ft_atoi((format + 1));
	return (width);
}

int	dot_num_sec(const char *format, int *count, va_list args, int i)
{
	int		width;
	int		argument;
	int		argument_l;
	va_list	argum;
	va_list	arglen;

	va_copy(argum, args);
	va_copy(arglen, args);
	(1) && (argument = va_arg(argum, int), width = ft_atoi(format));
	while (ft_isdigit(*format))
		(1) && (format++, (*count)++, i--);
	argument_l = calculate_lenght(format[i], arglen);
	if (format[i] == 's' && argument_l < ft_atoi(format + 1))
		width -= argument_l;
	else if ((format[i] != 's') && argument < 0 && width > ft_atoi(format + 1))
		width = dot_numbers_helper_sec(format, argument_l, width, i);
	else if (argument_l > ft_atoi(format + 1) && (format[i] != 's'))
	{
		if (argument == 0)
			argument_l--;
		width -= argument_l;
	}
	else
		width -= ft_atoi((format + 1));
	return (width);
}

int	numbers_else_sec(const char *format, int *count, va_list args, int i)
{
	int		width;
	va_list	arglen;
	int		returned_len;

	returned_len = 0;
	va_copy(arglen, args);
	if (format[0] == '0')
		return (0);
	width = ft_atoi(format) - calculate_lenght(format[i], arglen);
	if (format[i] == 'p')
		width -= 2;
	while (ft_isdigit(*format))
		(1) && (format++, (*count)++);
	return (width);
}
