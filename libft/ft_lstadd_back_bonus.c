/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamrene <kamrene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 11:33:07 by kamrene           #+#    #+#             */
/*   Updated: 2024/11/03 09:50:08 by kamrene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*checks if list or node are NULL then returns NULL,
if the node pointed by lst is NULL the new node is in front,
iterate until head->next is NULL then it will point on new node */

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*head;

	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	head = *lst;
	while (head->next)
	{
		head = head->next;
	}
	head->next = new;
}
