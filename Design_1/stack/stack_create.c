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

t_stack	*stack_create(void)
{
	t_stack	*self;

	self = memory_create(1, sizeof(t_stack));
	if (!self)
		return (0);
	self->top = list_create();
	self->top->data = 0;
	self->free_node = 0;
	self->size = 1;
	self->count = 0;
	return (self);
}
