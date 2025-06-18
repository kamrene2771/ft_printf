/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_functions_bonus_1.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamrene <kamrene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 17:36:28 by kamrene           #+#    #+#             */
/*   Updated: 2024/12/16 10:34:03 by kamrene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	zero_flag_lenght(char c, va_list arglen)
{
	int		lenght;
	char	*tmp;
	char	*temp;

	(1) && (lenght = 0, tmp = NULL);
	if (c == 's')
	{
		temp = va_arg(arglen, char *);
		if (!temp)
			temp = "(null)";
		lenght = ft_strlen(temp);
	}
	else if (c == 'd' || c == 'i')
	{
		tmp = ft_itoa(va_arg(arglen, int));
		lenght = ft_strlen(tmp);
		if (tmp[0] == '-')
			ft_putchar('-');
		free(tmp);
	}
	else if (c == '%')
		lenght = 1;
	if (ft_strchr("xXup", c))
		lenght = lenght_dot_helper(arglen, c);
	return (lenght);
}

int	calculate_lenght(char c, va_list arglen)
{
	int		lenght;
	char	*tmp;

	(1) && (lenght = 0, tmp = NULL);
	if (c == 's')
	{
		tmp = va_arg(arglen, char *);
		if (!tmp)
			tmp = "(null)";
		lenght = ft_strlen(tmp);
	}
	else if (c == 'c')
		lenght = 1;
	else if (c == 'd' || c == 'i')
	{
		(1) && (tmp = ft_itoa(va_arg(arglen, int)), lenght = ft_strlen(tmp));
		if (*tmp == '0')
			lenght = 1;
		free(tmp);
	}
	else if (c == '%')
		lenght = 1;
	if (ft_strchr("xXup", c))
		lenght = lenght_dot_helper(arglen, c);
	return (lenght);
}

char	*ft_itoa_base_zero(unsigned int n, const char *base)
{
	char			*result;
	unsigned int	tmp;
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
