/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamrene <kamrene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 01:10:11 by kamrene           #+#    #+#             */
/*   Updated: 2024/10/30 07:54:06 by kamrene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;

	i = 0;
	if (ft_strlen(needle) == 0)
		return ((char *)haystack);
	while (*haystack && i < len)
	{
		if (*haystack == *needle && (ft_strlen(needle) + i) <= len)
		{
			if (ft_strncmp(haystack, needle, ft_strlen(needle)) == 0)
			{
				return ((char *)haystack);
			}
		}
		haystack++;
		i++;
	}
	return (NULL);
}
