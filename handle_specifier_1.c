/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_specifier_1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamrene <kamrene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 18:06:07 by kamrene           #+#    #+#             */
/*   Updated: 2024/12/12 18:11:47 by kamrene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handle_pointer(void *ptr)
{
	unsigned long	addr;
	char			*hex;
	int				len;

	addr = (unsigned long)ptr;
	hex = ft_itoa_base(addr, "0123456789abcdef");
	len = handle_str("0x");
	len += handle_str(hex);
	free(hex);
	return (len);
}

int	handle_ptr_zero(va_list args)
{
	int				len;
	void			*ptr;
	unsigned long	addr;
	char			*hex;

	len = 0;
	ptr = va_arg(args, void *);
	addr = (unsigned long)ptr;
	hex = ft_itoa_base(addr, "0123456789abcdef");
	len += handle_str(hex);
	free(hex);
	return (len);
}
