/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_bonus_7.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamrene <kamrene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 16:18:48 by kamrene           #+#    #+#             */
/*   Updated: 2024/12/16 13:08:18 by kamrene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*search_help(const char *format, int *count, const char *flag)
{
	const char	*temp;
	char		*specifier;
	int			i;
	char		*tmp;

	i = 0;
	temp = format + *count - 1;
	while (temp[i])
	{
		if (ft_strchr("cspdiu%xX", temp[i]))
			break ;
		i++;
	}
	specifier = ft_substr(temp, 0, i + 1);
	tmp = specifier;
	specifier = ft_strjoin(flag, specifier);
	free(tmp);
	return (specifier);
}

int	sharp_search(const char *format, va_list args, int *count, int check)
{
	int		i;
	char	*specifier;
	int		returned_len;
	va_list	arglen;
	int		skip;

	(1) && (i = 0, skip = 0);
	while (*format && ft_strchr("-.0", *format))
		(1) && (format++, (*count)++);
	va_copy(arglen, args);
	while (format[i])
		if (ft_strchr("cspdiu%xX", format[++i]))
			break ;
	if (va_arg(arglen, int) != 0 && (format[i] == 'x' || format[i] == 'X'))
		skip = 2;
	while (*format && ft_strchr("#+ ", *format))
		(1) && (format++, (*count)++);
	specifier = add_flag(format, count, check);
	returned_len = width_flags_second(specifier, args, count, skip);
	specifier = search_help(specifier, count, "#");
	returned_len += substr_flags_second((char *)specifier, args, count);
	free(specifier);
	(*count)--;
	return (returned_len);
}

int	look_for_all(const char *format)
{
	int	i;
	int	sign[3];
	int	returned_val;

	i = 0;
	returned_val = 0;
	(1) && (sign[0] = 0, sign[1] = 0, sign[2] = 0);
	while (!ft_strchr("cspdiu%xX", format[i]) && format[i])
	{
		if (format[i] == '#')
			sign[0]++;
		else if (format[i] == '+')
			sign[1]++;
		else if (format[i] == ' ')
			sign[2]++;
		i++;
	}
	returned_val = look_for_all_helper(format, i, sign);
	return (returned_val);
}

int	look_for_all_helper(const char *format, int i, int *sign)
{
	int	returned_val;

	returned_val = 0;
	if (sign[0] > 0 && (format[i] == 'x' || format[i] == 'X'))
		returned_val = 1;
	else if (sign[1] > 0 && (format[i] == 'd' || format[i] == 'i'))
		returned_val = 2;
	else if (sign[2] > 0 && (format[i] == 'd' || format[i] == 'i'))
		returned_val = 3;
	else if (sign[0] > 0)
		returned_val = 1;
	else if (sign[1] > 0)
		returned_val = 2;
	else if (sign[2] > 0)
		returned_val = 3;
	else
		returned_val = 0;
	return (returned_val);
}

int	space_search(const char *format, va_list args, int *count, int check)
{
	int		i;
	char	*specifier;
	int		returned_len;
	int		skip;
	va_list	arglen;

	(1) && (skip = 0, i = 0, specifier = NULL);
	while (*format && ft_strchr("-.0", *format))
		(1) && (format++, (*count)++);
	va_copy(arglen, args);
	while (format[i])
		if (ft_strchr("cspdiu%xX", format[++i]))
			break ;
	if (va_arg(arglen, int) >= 0 && (format[i] == 'd' || format[i] == 'i'))
		skip = 1;
	while (*format && ft_strchr("#+ ", *format))
		(1) && (format++, (*count)++);
	specifier = add_flag(format, count, check);
	returned_len = width_flags_second(specifier, args, count, skip);
	specifier = search_help(specifier, count, " ");
	returned_len += substr_flags_second((char *)specifier, args, count);
	(1) && (free(specifier), (*count)--);
	return (va_end(arglen), returned_len);
}
