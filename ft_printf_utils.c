/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamrene <kamrene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 16:14:05 by kamrene           #+#    #+#             */
/*   Updated: 2024/12/12 18:04:56 by kamrene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int	ft_putstr(char *str)
{
	int	len;

	len = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (str[len])
	{
		ft_putchar(str[len++]);
	}
	return (len);
}

char	*ft_itoa_base(unsigned long n, const char *base)
{
	char			*result;
	unsigned long	tmp;
	int				base_len;
	int				len;

	(1) && (base_len = 0, tmp = n, len = 1);
	while (base[base_len])
		base_len++;
	while (tmp / base_len)
	{
		tmp /= base_len;
		len++;
	}
	result = malloc(len + 1);
	if (!result)
		return (NULL);
	result[len] = '\0';
	while (len > 0)
	{
		len--;
		result[len] = base[n % base_len];
		n /= base_len;
	}
	return (result);
}

int	ft_process_specifier(char specifier, va_list args)
{
	if (specifier == 'c')
		return (handle_char(va_arg(args, int)));
	else if (specifier == 's')
		return (handle_str(va_arg(args, char *)));
	else if (specifier == 'd' || specifier == 'i')
		return (handle_int(va_arg(args, int)));
	else if (specifier == 'u')
		return (handle_unsigned(va_arg(args, unsigned int)));
	else if (specifier == 'x' || specifier == 'X')
		return (handle_hex(va_arg(args, unsigned int), specifier));
	else if (specifier == 'p')
		return (handle_pointer(va_arg(args, void *)));
	else
		return (ft_putchar(specifier));
	return (0);
}
