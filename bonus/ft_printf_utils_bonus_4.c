/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_bonus_4.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamrene <kamrene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 13:22:07 by kamrene           #+#    #+#             */
/*   Updated: 2024/12/14 23:25:44 by kamrene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	substr_flags_second(const char *format, va_list args, int *count)
{
	int		len;
	int		end_off_flag;
	va_list	arglen;

	(1) && (len = 0, end_off_flag = 0);
	va_copy(arglen, args);
	while (format[len])
	{
		if (ft_strchr("dis%cuxXp", format[len]))
		{
			end_off_flag = 1;
			break ;
		}
		len++;
	}
	if (end_off_flag == 1)
	{
		if (format[0] == ' ')
			len = handle_space(format, args, len, count);
		else if (format[0] == '#')
			len = handle_sharp(format, args, len, count);
		else if (format[0] == '+')
			len = handle_plus(format, args, len, count);
	}
	return (va_end(arglen), len);
}

int	substr_flags(const char *format, va_list args, int *count)
{
	int	len;

	len = 0;
	while (format[len] && !ft_strchr("dis%cuxXp", format[len]))
		len++;
	if (!format[len])
		return (0);
	if (format[0] == '-')
		return (handle_minus(format, args, count, len));
	if (format[0] == '0')
		return (z_m_flag(format, count, len, args));
	if (format[0] == '.')
	{
		if (format[len] != 's')
			return (handle_dot_zero(format, args, count, len));
		return (handle_dot_string(format, args, count, len));
	}
	return (len);
}

int	z_m_flag(const char *format, int *count, int len, va_list args)
{
	int		i;
	int		r_l;
	va_list	arglen;
	int		h1;

	va_copy(arglen, args);
	(1) && (r_l = 0, h1 = ft_atoi(format), i = check((char *)format));
	if (format[i] == '-' || (format[i] == '.' && h1 == 0))
	{
		if (va_arg(arglen, int) < 0)
			count[1] = 0;
		if (count[1] == 1)
			r_l = ft_putchar('+');
		(1) && (format += i, *count += i, len -= i);
		if (format[0] == '-')
			return (r_l += handle_minus(format, args, count, len));
		else if (format[0] == '.')
		{
			if (format[len] == 's')
				return (r_l += handle_dot_string(format, args, count, len));
			else
				return (r_l += handle_dot_zero(format, args, count, len));
		}
	}
	return (va_end(arglen), len = zm_flag_helper(format, args, count, len));
}

int	zm_flag_helper(const char *format, va_list args, int *count, int len)
{
	const char	*tmp;
	int			i;

	i = check((char *)format);
	tmp = format + i + 1;
	if (format[i] == '.' && check((char *)tmp) > 0)
	{
		format += i;
		*count += i;
		len -= i;
	}
	len = handle_zero(format, args, count, len);
	return (len);
}
