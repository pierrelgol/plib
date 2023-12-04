/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_remove_at.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 11:11:14 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/04 11:11:14 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"
#include <stdio.h>

static void	list_node_remove_head(t_list *list)
{
	t_node	*node;

	if (!list || !list->head)
		return ;
	node = list->head;
	list->head = node->next;
	if (!list->head)
		list->tail = 0;
	else
		list->head->prev = 0;
	list_node_destroy(node);
}

static void	list_node_remove_tail(t_list *list)
{
	t_node	*node;

	if (!list || !list->tail)
		return ;
	node = list->tail;
	list->tail = node->prev;
	if (!list->tail)
		list->head = 0;
	else
		list->tail->next = 0;
	list_node_destroy(node);
}

static void	list_node_remove_next(t_list *list, t_node *node)
{
	t_node	*to_remove;

	if (!list || !node || !node->next)
		return ;
	to_remove = node->next;
	node->next = to_remove->next;
	if (!node->next)
		list->tail = node;
	else
		node->next->prev = node;
	list_node_destroy(to_remove);
}

t_list	*list_remove_at(t_list *list, unsigned int index)
{
	t_node	*node;

	if (!list)
		return (0);
	if (index == 0)
		list_node_remove_head(list);
	else if (index < list_size(list))
	{
		node = list_node_at(list->head, index);
		list_node_remove_next(list, node);
	}
	else
		list_node_remove_tail(list);
	return (list);
}
