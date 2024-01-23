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

t_stack	*stack_create(struct s_allocator *allocator)
{
	t_stack	*stack;

	stack = allocator->create(allocator, sizeof(t_stack));
	if (!stack)
		return (0);
	stack->allocator = allocator;
	stack->top = list_create(allocator);
	stack->top->data = 0;
	stack->free_node = 0;
	stack->size = 1;
	stack->count = 0;
	return (stack);
}
