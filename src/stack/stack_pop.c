/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_pop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 21:05:11 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/05 21:05:12 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/plib.h"

void	*stack_pop(t_stack *stack)
{
	void	*data;
	t_list	*node;

	if (!stack || stack_is_empty(stack))
		return (0);
	node = list_pop_at(&stack->top, 0);
	data = node->data;
	node->data = 0;
	list_push_at(&stack->free_node, node, 0);
	stack->count -= 1;
	if ((stack->size / stack->count) >= 4)
		stack_shrink(stack);
	return (data);
}
