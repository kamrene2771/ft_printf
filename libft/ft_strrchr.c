/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamrene <kamrene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 08:19:33 by kamrene           #+#    #+#             */
/*   Updated: 2024/10/30 08:23:59 by kamrene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	f;
	int		len;

	len = ft_strlen(s);
	f = (char)c;
	while (*s)
		s++;
	if (f == '\0')
	{
		return ((char *)s);
	}
	s--;
	while (len--)
	{
		if (*s == f)
		{
			return ((char *)s);
		}
		s--;
	}
	return (NULL);
}
