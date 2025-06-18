/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamrene <kamrene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 05:56:32 by kamrene           #+#    #+#             */
/*   Updated: 2024/11/04 10:17:27 by kamrene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* allocate new array , aplly f  on s and 
return new array with altered characters*/

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t			srclen;
	char			*dst;
	char			*res;
	unsigned int	i;

	if (!s || !f)
		return (NULL);
	srclen = ft_strlen(s);
	dst = (char *)malloc((srclen + 1) * sizeof(char));
	if (dst == NULL)
		return (NULL);
	res = dst;
	i = 0;
	while (s[i])
	{
		dst[i] = f(i, s[i]);
		i++;
	}
	dst[i] = '\0';
	return (res);
}
