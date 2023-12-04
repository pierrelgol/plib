/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_destroy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 11:10:33 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/04 11:10:34 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

t_list	*list_destroy(t_list *list)
{
	t_node	*temp;

	if (!list)
		return (0);
	while (list->head)
	{
		temp = list->head;
		list->head = temp->next;
		list_node_destroy(temp);
	}
	return (memory_dealloc(list));
}
