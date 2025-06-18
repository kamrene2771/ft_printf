/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamrene <kamrene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 04:07:29 by kamrene           #+#    #+#             */
/*   Updated: 2024/11/03 15:23:21 by kamrene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*concat(size_t len, char *dest, char *s)
{
	if (s)
		while (len--)
			*dest++ = *s++;
	return (dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1len;
	size_t	s2len;
	size_t	all_len;
	char	*dest;
	char	*cat;

	s1len = 0;
	s2len = 0;
	if (!s1 && !s2)
		return (NULL);
	if (s1)
		s1len = ft_strlen(s1);
	if (s2)
		s2len = ft_strlen(s2);
	all_len = s1len + s2len + 1;
	dest = (char *)malloc(all_len * sizeof(char));
	if (dest == NULL)
		return (NULL);
	cat = dest;
	dest = concat(s1len, dest, (char *)s1);
	dest = concat(s2len, dest, (char *)s2);
	*dest = '\0';
	return (cat);
}
