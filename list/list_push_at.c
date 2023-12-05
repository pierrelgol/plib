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

#include "../plib.h"

t_list	*list_push_at(t_list **list, t_list *node, unsigned int index)
{
	t_list	*temp;

	if (!list || !node)
		return (0);
	if (index == 0)
		return (list_push_front(list, node));
	else if (index >= list_length(*list))
		return (list_push_back(list, node));
	else
	{
		temp = (*list);
		while (temp->next && --index)
			temp = temp->next;
		node->next = temp->next;
		temp->next = node;
	}
	return (node);
}
