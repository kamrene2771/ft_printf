/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamrene <kamrene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 01:10:17 by kamrene           #+#    #+#             */
/*   Updated: 2024/12/14 21:31:14 by kamrene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned long long	convert(const char *str)
{
	unsigned long long	result;

	result = 0;
	while (ft_isdigit((int)*str))
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	return (result);
}
/*skips unprintable chars and then checks
if the char before digit if - or + ,due to using unsigned i can hold*/

int	ft_atoi(const char *str)
{
	int					sign;
	unsigned long long	result;

	sign = 1;
	result = 0;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	while (*str == '-' || *str == '+')
		str++;
	result = convert(str);
	return ((int)(sign * result));
}
