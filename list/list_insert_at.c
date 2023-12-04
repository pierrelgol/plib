/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_insert_at.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 11:11:05 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/04 11:11:05 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"
#include <stdio.h>

static void	list_node_insert_head(t_list *list, t_node *new_head)
{
	if (!list || !new_head)
		return ;
	if (!list->head)
	{
		list->head = new_head;
		list->tail = new_head;
		new_head->prev = 0;
		new_head->next = list->tail;
	}
	else
	{
		new_head->next = list->head;
		list->head->prev = new_head;
		list->head = new_head;
		new_head->prev = 0;
	}
}

static void	list_node_insert_tail(t_list *list, t_node *new_tail)
{
	if (!list || !new_tail)
		return ;
	if (!list->tail)
	{
		list->tail = new_tail;
		new_tail->prev = 0;
		new_tail->next = 0;
	}
	else
	{
		new_tail->prev = list->tail;
		list->tail->next = new_tail;
		list->tail = new_tail;
		new_tail->next = 0;
	}
}

static void	list_node_insert_after(t_node *prev, t_node *curr)
{
	t_node	*next;

	if (!prev || !curr)
		return ;
	next = prev->next;
	curr->prev = prev;
	curr->next = next;
	if (next != 0)
		next->prev = curr;
	prev->next = curr;
}

t_list	*list_insert_at(t_list *list, void *data, unsigned int index)
{
	t_node	*new_node;
	t_node	*node;

	if (!list)
		return (0);
	new_node = list_node_create(data);
	if (!new_node)
		return (0);
	if (index == 0)
		list_node_insert_head(list, new_node);
	else if (index < list_size(list))
	{
		node = list_node_at(list->head, index);
		list_node_insert_after(node, new_node);
	}
	else
		list_node_insert_tail(list, new_node);
	return (list);
}
