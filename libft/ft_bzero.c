/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamrene <kamrene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 22:30:43 by kamrene           #+#    #+#             */
/*   Updated: 2024/11/03 08:12:51 by kamrene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*while n is not 0 it will replace characters
with \0 and ints with 0 */
void	ft_bzero(void *s, size_t n)
{
	while (n != 0)
	{
		*(unsigned char *)s = 0;
		s++;
		n--;
	}
}
