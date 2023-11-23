/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plib_list_insert_after.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 09:16:30 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/11/23 09:16:31 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

t_list	*plib_list_insert_after(t_list *node, void *data)
{
	t_list	*new_node;

	new_node = plib_list_create(data);
	if (new_node)
	{
		new_node->next = node->next;
		node->next = new_node;
	}
	return (new_node);
}
