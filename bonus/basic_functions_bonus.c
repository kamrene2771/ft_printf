/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_functions_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamrene <kamrene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 16:05:50 by kamrene           #+#    #+#             */
/*   Updated: 2024/12/15 17:35:18 by kamrene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	check(char *flag)
{
	int	i;

	i = 0;
	while (flag[i] && !ft_strchr("discu%xXp", flag[i]))
	{
		if (flag[i] == '.' || flag[i] == '-')
			return (i);
		i++;
	}
	return (0);
}

void	handle_zero_negative(va_list args)
{
	long	nbr;
	char	*number;

	nbr = (long)va_arg(args, int);
	if (nbr < 0)
	{
		nbr *= -1;
	}
	number = ft_itoa(nbr);
	handle_str(number);
	free(number);
}

int	handle_dot_negative(va_list args)
{
	int		sign;
	long	nbr;
	char	*number;

	sign = 0;
	nbr = (long)va_arg(args, int);
	if (nbr < 0)
	{
		nbr *= -1;
		sign = 1;
	}
	number = ft_itoa(nbr);
	handle_str(number);
	free(number);
	return (sign);
}

int	zero_dot_flag_lenght(char c, va_list arglen, int flag, int *h1)
{
	int		lenght;
	char	*tmp;

	(1) && (tmp = NULL, lenght = 0);
	if (c == 's')
		lenght = ft_strlen(va_arg(arglen, char *));
	else if (c == 'd' || c == 'i')
	{
		tmp = ft_itoa(va_arg(arglen, int));
		lenght = ft_strlen(tmp);
		if (tmp[0] == '-' && flag == 0)
			ft_putchar('-');
		if (tmp[0] == '-')
		{
			lenght -= 1;
			h1[2] = 1;
		}
		free(tmp);
	}
	else if (c == '%')
		lenght = 1;
	if (ft_strchr("xXup", c))
		lenght = lenght_dot_helper(arglen, c);
	return (lenght);
}

int	lenght_dot_helper(va_list arglen, int c)
{
	char			*tmp;
	void			*ptr;
	unsigned long	addr;
	int				lenght;

	(1) && (tmp = NULL, lenght = 0, addr = 0, ptr = NULL);
	if (c == 'u')
	{
		tmp = ft_itoa_base_zero(va_arg(arglen, int), "0123456789");
		lenght = ft_strlen(tmp);
	}
	else if (c == 'p')
	{
		ptr = va_arg(arglen, void *);
		addr = (unsigned long)ptr;
		tmp = ft_itoa_base(addr, "0123456789abcdef");
		lenght = ft_strlen(tmp);
	}
	else if (c == 'x' || c == 'X')
	{
		tmp = ft_itoa_base_zero(va_arg(arglen, int), "0123456789abcdef");
		lenght = ft_strlen(tmp);
	}
	free(tmp);
	return (lenght);
}
