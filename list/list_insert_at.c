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

t_list	*list_insert_at(t_list **list, void *data, unsigned int index)
{	
	t_list	*new_node;
	t_list	*temp;

	if (!list)
		return (0);
	if (index == 0)
		return (list_insert_front(list, data));
	else if (index >= list_length(*list))
		return (list_insert_back(list, data));
	else
	{
		new_node = list_create(data);
		if (!new_node)
			return (0);
		temp = (*list);
		while (temp->next && --index)
			temp = temp->next;
		new_node->next = temp->next;
		temp->next = new_node;
	}
	return (new_node);
}
