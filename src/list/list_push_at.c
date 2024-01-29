/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_puch_at.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 11:54:01 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/05 11:54:03 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/plib.h"

t_list	*list_push_front(t_list **list, t_list *new_head)
{
	if (!list || !new_head)
		return (0);
	if (!*list)
		(*list) = new_head;
	else
	{
		new_head->next = (*list);
		(*list) = new_head;
	}
	return (new_head);
}

t_list	*list_push_back(t_list **list, t_list *new_tail)
{
	t_list	*temp;

	if (!list || !new_tail)
		return (0);
	if (!*list)
		(*list) = new_tail;
	else
	{
		temp = (*list);
		while (temp->next)
			temp = temp->next;
		temp->next = new_tail;
	}
	return (new_tail);
}

t_list	*list_push_at(t_list **list, t_list *new_node, unsigned int index)
{
	t_list	*temp;

	if (!list || !new_node)
		return (0);
	if (index == 0)
		return (list_push_front(list, new_node));
	else if (index >= list_length(*list))
		return (list_push_back(list, new_node));
	else
	{
		temp = (*list);
		while (temp->next && --index)
			temp = temp->next;
		new_node->next = temp->next;
		temp->next = new_node;
	}
	return (new_node);
}
