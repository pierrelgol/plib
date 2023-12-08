/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 21:05:02 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/05 21:05:03 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

void *stack_push(t_stack *self, void *data)
{
	unsigned int i;
	t_list *new;

	if (!self)
		return (0);
	if (self->count == self->size)
	{
		i = 0;
		while (i < (self->size << 1))
			list_insert_front(&self->free_node, data);
		self->size <<= 1;
		stack_push(self, data);
	}
	new = list_pop_front(&self->free_node);
	new->data = data;
	list_push_front(&self->top, new);
	self->count += 1;
	return (data);
}
