/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamrene <kamrene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 11:33:38 by kamrene           #+#    #+#             */
/*   Updated: 2024/11/03 09:55:49 by kamrene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*new-> next will point on node pointed by lst 
and lst will point on new node */

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!new || !lst)
		return ;
	new->next = *lst;
	*lst = new;
}
