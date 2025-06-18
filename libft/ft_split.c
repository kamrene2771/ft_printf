/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamrene <kamrene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 17:58:15 by kamrene           #+#    #+#             */
/*   Updated: 2024/11/05 14:17:48 by kamrene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*counts how many words in the arc string*/

static int	howmanyc(char *s, char c)
{
	int	count;
	int	flag;

	count = 0;
	flag = 0;
	while (*s)
	{
		if (*s != c && flag == 0)
		{
			count++;
			flag = 1;
		}
		else if (*s == c)
		{
			flag = 0;
		}
		s++;
	}
	return (count);
}
/*frees all lines in an array and free the first element*/

static void	free_all(char **arr, int i)
{
	while (i >= 0)
		free(arr[i--]);
	free(arr);
}
/*allocate every line and copies the word*/

static char	*allocation(char *start, char *end)
{
	char	*arr;
	char	*dest;

	arr = (char *)malloc((end - start + 1) * sizeof(char));
	if (!arr)
		return (NULL);
	dest = arr;
	while (start < end)
		*arr++ = *start++;
	*arr = '\0';
	return (dest);
}
/*manage the start end pointer 
calls the functions ,
null terminate the array*/

static char	**process(char *start, char *end, char **arr, char c)
{
	int	i;

	i = 0;
	while (*end)
	{
		if (*end == c)
		{
			if (end > start)
			{
				arr[i] = allocation(start, end);
				if (!arr[i++])
					return (free_all(arr, i - 1), NULL);
			}
			start = end + 1;
		}
		end++;
	}
	if (end > start)
	{
		arr[i] = allocation(start, end);
		if (!arr[i++])
			return (free_all(arr, i - 1), NULL);
	}
	arr[i] = NULL;
	return (arr);
}
/*allocate 2D array and returns it after process ends*/

char	**ft_split(char const *s, char c)
{
	char	**arr;
	char	*start;
	char	*end;

	if (!s)
		return (NULL);
	arr = (char **)malloc((howmanyc((char *)s, c) + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	start = (char *)s;
	end = (char *)s;
	arr = process(start, end, arr, c);
	return (arr);
}
