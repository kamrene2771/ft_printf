/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamrene <kamrene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 22:51:54 by kamrene           #+#    #+#             */
/*   Updated: 2024/11/05 18:09:35 by kamrene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*if count * size overflows block will allocate invalid memory
so i check if max size /size is smaller than count it means that
count * size > sizemax so it shoud return NULL
malloc 0 on mac allocates a fixed chunck of 16 bytes so no need to handle it*/

void	*ft_calloc(size_t count, size_t size)
{
	size_t	block;
	char	*ptr;

	if (size != 0 && count > SIZE_MAX / size)
		return (NULL);
	block = count * size;
	ptr = malloc(block);
	if (!ptr)
		return (NULL);
	ft_memset(ptr, 0, block);
	return (ptr);
}
