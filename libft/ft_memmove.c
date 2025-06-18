/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamrene <kamrene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 08:00:38 by kamrene           #+#    #+#             */
/*   Updated: 2024/11/06 19:57:31 by kamrene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*dest;
	const unsigned char	*source = (const unsigned char *)src;

	if (dst == NULL && src == NULL)
		return (NULL);
	if (len == 0)
		return (dst);
	dest = (unsigned char *)dst;
	if (dest < source)
	{
		while (len--)
		{
			*dest++ = *source++;
		}
	}
	else
	{
		dest += len;
		source += len;
		while (len--)
			*(--dest) = *(--source);
	}
	return (dst);
}
