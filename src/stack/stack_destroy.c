/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_destroy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 21:04:47 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/05 21:04:50 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/plib.h"

t_stack	*stack_destroy(t_stack *stack)
{
	struct s_allocator *allocator;

	if (!stack)
		return (0);
	allocator = stack->allocator;
	if (stack->top)
		list_destroy(allocator, stack->top);
	if (stack->free_node)
		list_destroy(allocator, stack->free_node);
	return (allocator->destroy(allocator, stack));
}
