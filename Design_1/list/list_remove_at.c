/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_remove_at.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 20:58:34 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/04 20:58:34 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

static void	*list_remove_front(t_list **list)
{
	t_list	*temp;
	void	*data;

	if (!list || !*list)
		return (0);
	temp = (*list);
	data = temp->data;
	(*list) = (*list)->next;
	memory_destroy(temp);
	return (data);
}

static void	*list_remove_back(t_list **list)
{
	t_list	*prev;
	t_list	*curr;
	void	*data;

	if (!list || !*list)
		return (0);
	curr = (*list);
	prev = curr;
	while (curr->next)
	{
		prev = curr;
		curr = curr->next;
	}
	data = curr->data;
	prev->next = 0;
	memory_destroy(curr);
	return (data);
}

void	*list_remove_at(t_list **list, unsigned int index)
{
	t_list	*prev;
	t_list	*curr;
	void	*data;

	if (!list || !*list)
		return (0);
	if (index == 0)
		return (list_remove_front(list));
	else if (index >= list_length(*list))
		return (list_remove_back(list));
	else
	{
		curr = (*list);
		prev = curr;
		while (index--)
		{
			prev = curr;
			curr = curr->next;
		}
		data = curr->data;
		prev->next = curr->next;
		memory_destroy(curr);
		return (data);
	}
}
