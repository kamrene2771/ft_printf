/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_bonus_2.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamrene <kamrene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 12:54:40 by kamrene           #+#    #+#             */
/*   Updated: 2024/12/15 17:53:20 by kamrene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	handle_minus(const char *format, va_list args, int *count, int len)
{
	int		how_many;
	int		lenght;
	char	*buffer;
	int		c;

	how_many = 0;
	lenght = 0;
	c = format[0];
	while (*format == '-' && *(format + 1) == '-')
		(1) && (format++, (*count)++, len--);
	buffer = ft_substr(format, 1, len);
	if (check(buffer) > 0 || buffer[0] == '.')
		return (free(buffer), handle_both(buffer, args, count, c));
	how_many = ft_atoi(buffer);
	lenght = how_many - count[1] - count[2];
	*count += ft_strlen(buffer) + 1;
	free(buffer);
	len = ft_process_specifier(format[len], args);
	how_many = how_many - len - count[1] - count[2];
	if (how_many > 0)
		while (how_many--)
			ft_putchar(' ');
	else
		lenght = len;
	return (lenght);
}

int	handle_dot_zero(const char *format, va_list args, int *count, int len)
{
	int		how_many[3];
	char	*buffer;
	int		c;
	int		returned_len;
	va_list	arglen;

	*how_many = 0;
	how_many[1] = count[1];
	c = format[0];
	va_copy(arglen, args);
	buffer = ft_substr(format, 1, len);
	if (c == '.')
		c = buffer[check(buffer)];
	if (check(buffer) > 0)
		return (free(buffer), va_end(arglen), handle_both(buffer, args, count,
				c));
	*how_many = ft_atoi(buffer);
	if (format[len] == '%')
		*how_many = 0;
	*count += ft_strlen(buffer) + 1;
	free(buffer);
	buffer = NULL;
	returned_len = print_dot_zero(how_many, (char *)format, args, len);
	va_end(arglen);
	return (returned_len);
}

int	print_dot_zero(int *h_m, char *format, va_list args, int len)
{
	int		returned_len;
	int		lenght;
	va_list	arglen;
	va_list	argum;
	int		h2;

	va_copy(arglen, args);
	va_copy(argum, args);
	lenght = zero_dot_flag_lenght(format[len], arglen, 0, h_m);
	va_end(arglen);
	(1) && (h2 = *h_m, returned_len = lenght, *h_m = *h_m - lenght);
	if (format[len] == 'p')
		returned_len += ft_putstr("0x");
	if (*h_m > 0)
		while ((*h_m)--)
			returned_len += ft_putchar('0');
	if (va_arg(argum, int) == 0 && h2 == 0)
		return (va_arg(args, int), handle_str("\0"));
	if (format[len] == 'd' || format[len] == 'i')
		returned_len += handle_dot_negative(args);
	else if (format[len] == 'p')
		handle_ptr_zero(args);
	else
		ft_process_specifier(format[len], args);
	return (va_end(argum), returned_len);
}

int	handle_zero(const char *format, va_list args, int *count, int len)
{
	int		how_many[2];
	char	*buffer;
	int		c;
	int		returned_len;
	va_list	arglen;

	(1) && (*how_many = 0, c = format[0]);
	va_copy(arglen, args);
	buffer = ft_substr(format, 1, len);
	if (c == '.')
		c = buffer[check(buffer)];
	if (check(buffer) > 0)
		return (free(buffer), va_end(arglen), handle_both(buffer, args, count,
				c));
	*how_many = ft_atoi(buffer);
	*count += ft_strlen(buffer) + 1;
	how_many[1] = count[1] + count[2];
	free(buffer);
	buffer = NULL;
	returned_len = print_zero(how_many, (char *)format, args, len);
	va_end(arglen);
	return (returned_len);
}

int	print_zero_helper(char c, int lenght, int *how_many)
{
	if (c == 'p')
		lenght += ft_putstr("0x");
	*how_many -= lenght + how_many[1];
	return (lenght);
}
