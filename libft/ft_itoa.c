/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamrene <kamrene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 01:09:59 by kamrene           #+#    #+#             */
/*   Updated: 2024/12/12 18:08:56 by kamrene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*reverts the string*/
static void	swap(char *start, char *end)
{
	char	tmp;

	while (start < end)
	{
		tmp = *start;
		*start++ = *end;
		*end-- = tmp;
	}
}
/* counts how many elements in a number to allocate*/

static char	*calc_alloc(long long sign, long long num)
{
	long long	len;
	long		count;
	char		*str;

	len = num;
	count = 0;
	while (len > 0)
	{
		len /= 10;
		count++;
	}
	if (sign < 0 || num == 0)
		count++;
	str = (char *)malloc((count + 1) * sizeof(char));
	return (str);
}
/* converts from int to arr*/

static char	*convert(long long num, char *str, long long sign)
{
	while (num > 0)
	{
		*str++ = num % 10 + '0';
		num /= 10;
	}
	if (sign < 0)
		*str++ = '-';
	*str = '\0';
	return (str);
}
/* returns NULL if the allocation fails ,calls
the functions and return dst*/

char	*ft_itoa(long n)
{
	long long	sign;
	long long	num;
	char		*dst;
	char		*str;

	num = n;
	sign = 1;
	if (num < 0)
	{
		num = -num;
		sign = -1;
	}
	str = calc_alloc(sign, num);
	if (!str)
		return (NULL);
	dst = str;
	if (num == 0)
	{
		(1) && (*dst++ = '0',*dst-- = '\0');
		return (dst);
	}
	str = convert(num, str, sign);
	swap(dst, --str);
	return (dst);
}
