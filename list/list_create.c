/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_create.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 11:10:24 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/04 11:10:25 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

t_list	*list_create(void *data)
{
	t_list	*self;

	self = memory_alloc(1, sizeof(t_list));
	if (!self)
		return (0);
	self->head = list_node_create(data);
	if (!self->head)
		return (list_destroy(self));
	self->tail = self->head;
	self->head->prev = 0;
	self->head->next = self->tail;
	self->tail->prev = self->head;
	self->tail->next = 0;
	return (self);
}
