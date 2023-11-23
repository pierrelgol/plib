/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plib_list_remove.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 09:17:55 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/11/23 09:17:57 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

void	plib_list_remove(t_list **list, t_list *node)
{
	t_list	*temp;

	temp = NULL;
	if (*list == node)
	{
		*list = (*list)->next;
		plib_memory_dealloc(node);
		node = NULL;
	}
	else
	{
		temp = *list;
		while (temp->next && temp->next != node)
			temp = temp->next;
		if (temp->next)
		{
			temp->next = node->next;
			plib_memory_dealloc(node);
			node = NULL;
		}
	}
}
