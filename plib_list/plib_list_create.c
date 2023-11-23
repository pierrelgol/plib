/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plib_list_create.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 09:14:14 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/11/23 09:14:15 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

t_list	*plib_list_create(void *data)
{
	t_list	*new_node;

	new_node = plib_memory_alloc(1, sizeof(t_list));
	if (new_node != NULL)
	{
		new_node->next = NULL;
		new_node->data = data;
	}
	return (new_node);
}
