/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_insert_front.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 20:08:41 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/04 20:08:42 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

t_list	*list_insert_front(t_list **self, void *data)
{
	t_list	*new_head;

	if (!self)
		return (0);
	new_head = list_create(data);
	if (!new_head)
		return (0);
	if (!*self)
		(*self) = new_head;
	else
	{
		new_head->next = (*self);
		(*self) = new_head;
	}
	return (new_head);
}
