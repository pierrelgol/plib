/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_insert_at.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 20:50:39 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/04 20:50:40 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

static t_list	*list_insert_front(struct s_allocator *allocator,t_list **list, void *data)
{
	t_list	*new_head;

	if (!list)
		return (0);
	new_head = list_create(allocator);
	if (!new_head)
		return (0);
	new_head->data = data;
	if (!*list)
		(*list) = new_head;
	else
	{
		new_head->next = (*list);
		(*list) = new_head;
	}
	return (new_head);
}

static t_list	*list_insert_back(struct s_allocator *allocator, t_list **list, void *data)
{
	t_list	*new_tail;
	t_list	*temp;

	if (!list)
		return (0);
	new_tail = list_create(allocator);
	if (!new_tail)
		return (0);
	new_tail->data = data;
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

t_list	*list_insert_at(struct s_allocator *allocator, t_list **list, void *data, unsigned int index)
{
	t_list	*new_node;
	t_list	*temp;

	if (!list)
		return (0);
	if (index == 0)
		return (list_insert_front(allocator, list, data));
	else if (index >= list_length(*list))
		return (list_insert_back(allocator, list, data));
	else
	{
		new_node = list_create(allocator);
		if (!new_node)
			return (0);
		new_node->data = data;
		temp = (*list);
		while (temp->next && --index)
			temp = temp->next;
		new_node->next = temp->next;
		temp->next = new_node;
	}
	return (new_node);
}
