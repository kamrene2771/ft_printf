/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamrene <kamrene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 03:41:28 by kamrene           #+#    #+#             */
/*   Updated: 2024/11/04 21:21:18 by kamrene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*checks if character is in set*/

static int	isinset(char *set, char c)
{
	while (*set)
	{
		if (*set == c)
		{
			return (1);
		}
		set++;
	}
	return (0);
}
/*incr start until a character is not found in set*/

static char	*incr(char *start, char *set)
{
	if (!set)
		return (start);
	while (*start)
	{
		if (isinset((char *)set, *start))
			start++;
		else
			break ;
	}
	return (start);
}
/*decrement end until a character is not found in set*/

static char	*decr(char *start, char *end, char *set)
{
	if (!set)
		return (end);
	while (end != start)
	{
		if (isinset((char *)set, *end))
			end--;
		else
			break ;
	}
	return (end);
}
/*calls func ,
if start and end are equal mean all is trimmed*/

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*start;
	char	*end;
	size_t	destlen;
	char	*dest;
	char	*trimmed;

	destlen = 0;
	if (s1 != NULL && *s1 != '\0')
	{
		start = (char *)s1;
		end = (char *)s1 + ft_strlen(s1) - 1;
		start = incr(start, (char *)set);
		end = decr(start, end, (char *)set);
		destlen = end - start + 1;
		if (start > end)
			destlen = 0;
	}
	dest = (char *)malloc((destlen + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	trimmed = dest;
	while (destlen--)
		*dest++ = *start++;
	*dest = '\0';
	return (trimmed);
}
