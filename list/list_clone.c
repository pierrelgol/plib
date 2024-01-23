/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_clone.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 11:40:06 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/05 11:40:07 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

t_list	*list_clone(struct s_allocator *allocator, t_list **list)
{
	t_list	*clone;
	t_list	*temp;

	if (!list || !*list)
		return (0);
	temp = (*list)->next;
	clone = list_create(allocator);
	clone->data = (*list)->data;
	while (temp)
	{
		list_insert_at(allocator, &clone, temp->data, list_length(*list));
		temp = temp->next;
	}
	return (clone);
}
