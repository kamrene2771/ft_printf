/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamrene <kamrene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 20:42:13 by kamrene           #+#    #+#             */
/*   Updated: 2024/11/04 12:45:37 by kamrene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		srclen;
	char	*arr;
	char	*dest;

	srclen = ft_strlen(s1);
	arr = (char *)malloc((srclen + 1) * sizeof(char));
	if (arr == NULL)
	{
		return (NULL);
	}
	dest = arr;
	while (*s1)
	{
		*arr++ = *s1++;
	}
	*arr = '\0';
	return (dest);
}
