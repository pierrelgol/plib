/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 10:51:33 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/05 10:51:33 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

t_stack *stack_create(unsigned int type)
{
	t_stack     *self;
	t_list      *temp;
	unsigned int i;

	self = memory_alloc(1, sizeof(t_stack));
	if (!self)
		return (0);
	self->stack = list_create(0);
	i = 0;
	while (i < DEFAULT_SIZE)
	{
		if (!list_insert_front(&temp, 0))
		{
			list_destroy(temp);
			stack_destroy(self);
		}
		++i;
	}
	self->stack = temp;
	self->type = bit_set_bit(self->type, type);
	self->size = DEFAULT_SIZE;
	self->count = 0;
	return (self);
}
