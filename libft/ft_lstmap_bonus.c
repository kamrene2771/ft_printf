/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamrene <kamrene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 11:36:23 by kamrene           #+#    #+#             */
/*   Updated: 2024/11/06 19:51:18 by kamrene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*applies f on the old node content then stores
 it in a newcontent and allocates a new node,
if the new node is not allocated free the new content and return null, 
*/

static t_list	*create_new_node(void *content, void *(*f)(void *),
		void (*del)(void *))
{
	t_list	*new_node;
	void	*new_content;

	new_content = f(content);
	new_node = malloc(sizeof(t_list));
	if (!new_node)
	{
		del(new_content);
		return (NULL);
	}
	new_node->content = new_content;
	new_node->next = NULL;
	return (new_node);
}
/*
checks if a node allocation fails to clear all 
the list to prevent memory leaks,
if its the first node newlist point on the new node,
then current points on new node
else current.next point on new node;
*/

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*current;
	t_list	*new_node;

	new_list = NULL;
	if (!lst || !f || !del)
		return (NULL);
	while (lst)
	{
		new_node = create_new_node(lst->content, f, del);
		if (!new_node)
		{
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		if (!new_list)
			new_list = new_node;
		else
			current->next = new_node;
		current = new_node;
		lst = lst->next;
	}
	return (new_list);
}
