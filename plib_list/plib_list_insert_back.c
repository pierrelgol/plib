/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plib_list_insert_back.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 09:17:43 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/11/23 09:17:44 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

t_list	*plib_list_insert_back(t_list *list, void *data)
{
	t_list	*new_node;
	t_list	*temp;

	new_node = plib_list_create(data);
	if (new_node != NULL)
	{
		temp = list;
		while (temp != NULL)
		{
			if (temp->next == NULL)
			{
				temp->next = new_node;
				break ;
			}
			temp = temp->next;
		}
	}
	return (new_node);
}
