/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_specifier.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamrene <kamrene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 18:05:10 by kamrene           #+#    #+#             */
/*   Updated: 2024/12/12 18:18:58 by kamrene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handle_char(int c)
{
	return (ft_putchar(c));
}

int	handle_str(char *str)
{
	return (ft_putstr(str));
}

int	handle_int(int nbr)
{
	char	*number;
	int		len;

	number = ft_itoa(nbr);
	len = handle_str(number);
	free(number);
	return (len);
}

int	handle_unsigned(unsigned int nbr)
{
	char	*number;
	int		len;

	number = ft_itoa_base(nbr, "0123456789");
	len = handle_str(number);
	free(number);
	return (len);
}

int	handle_hex(unsigned int nbr, char specipier)
{
	char	*base;
	char	*number;
	int		len;

	if (specipier == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	number = ft_itoa_base(nbr, base);
	len = handle_str(number);
	free(number);
	return (len);
}
