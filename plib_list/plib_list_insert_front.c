/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plib_list_insert_front.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 09:16:11 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/11/23 09:16:11 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

t_list	*plib_list_insert_front(t_list *list, void *data)
{
	t_list	*new_node;

	new_node = plib_list_create(data);
	if (new_node != NULL)
		new_node->next = list;
	return (new_node);
}
