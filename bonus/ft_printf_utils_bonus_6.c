/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_bonus_6.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamrene <kamrene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 17:46:25 by kamrene           #+#    #+#             */
/*   Updated: 2024/12/16 13:06:45 by kamrene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	sharp_all(int *returned_len, const char *format, int *count,
		va_list args)
{
	int		len;
	int		argument;
	va_list	arglen;
	int		i;

	va_copy(arglen, args);
	len = returned_len[1];
	argument = va_arg(arglen, int);
	i = returned_len[2];
	if (i > 0)
	{
		if (argument < 0 && format[1] == '0' && format[len] != 'p')
			count[1] = 1;
		(1) && ((*count)++, *returned_len += substr_flags(++format, args,
				count));
	}
	else if (format[1] == '0')
		(1) && ((*count)++, *returned_len += substr_flags(++format, args,
				count));
	else
		(1) && (*count += len + 1,
			*returned_len = ft_process_specifier(*(++format), args));
	va_end(arglen);
}

void	sharp_helper(const char *format, int *r_l, int *count, va_list args)
{
	int		len;
	int		arg;
	va_list	arglen;
	int		i;

	va_copy(arglen, args);
	(1) && (len = r_l[1], arg = va_arg(arglen, int),
		i = check((char *)(format)));
	if (i > 0)
	{
		sharp_helper_sec(format, arg, r_l, count);
		*r_l += substr_flags(++format, args, count);
	}
	else if (format[1] == '0' && i == 0)
	{
		(*count)++;
		if (arg != 0)
			(1) && (count[1] = 2, *r_l = ft_putchar('0'), *r_l
				+= ft_putchar(format[len]));
		*r_l += substr_flags(++format, args, count);
	}
	else
		(1) && (*count += len + 1, *r_l += ft_process_specifier(*(++format),
				args));
	va_end(arglen);
}

int	count_flags(const char *format)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (format[i] && !ft_strchr("cspdiu%xX", format[i]))
	{
		if (format[i] == '-' || format[i] == '.')
			count++;
		i++;
	}
	return (count);
}

void	sharp_helper_sec(const char *format, int arg, int *r_l, int *count)
{
	const char	*tmp;
	int			i;
	int			len;

	len = r_l[1];
	i = check((char *)(format));
	tmp = format + i + 1;
	if (arg != 0 && format[1] == '0' && check((char *)(tmp)) > 0
		&& tmp[check((char *)(tmp))] == '.')
		(1) && (*r_l = ft_putchar('0'), *r_l += ft_putchar(format[len]));
	if (arg != 0)
		count[1] = 2;
	(*count)++;
}

int	plus_search(const char *format, va_list args, int *count, int check)
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
	if (va_arg(arglen, int) >= 0 && (format[i] == 'd' || format[i] == 'i'))
		skip = 1;
	while (*format && ft_strchr("#+ ", *format))
		(1) && (format++, (*count)++);
	specifier = add_flag(format, count, check);
	returned_len = width_flags_second(specifier, args, count, skip);
	specifier = search_help(specifier, count, "+");
	returned_len += substr_flags_second((char *)specifier, args, count);
	free(specifier);
	(*count)--;
	return (returned_len);
}
