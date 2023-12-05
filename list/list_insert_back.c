/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_insert_back.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 20:33:28 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/04 20:33:31 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

t_list	*list_insert_back(t_list **list, void *data)
{
	t_list	*new_node;
	t_list	*temp;

	if (!list)
		return (0);
	new_node = list_create(data);
	if (!new_node)
		return (0);
	if (!*list)
		(*list) = new_node;
	else
	{
		temp = (*list);
		while (temp->next)
			temp = temp->next;
		temp->next = new_node;
	}
	return (new_node);
}
