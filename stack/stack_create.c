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

t_stack *stack_create(void *data)
{
	t_stack     *self;
	unsigned int i;

	self = memory_alloc(1, sizeof(t_stack));
	if (!self)
		return (0);
	self->top = list_create(data);
	if (!self->top)
		return (stack_destroy(self));
	self->size = 1;
	self->count = 1;
	return (self);
}
