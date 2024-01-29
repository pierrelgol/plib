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

#include "../../include/plib.h"

void	*stack_push(t_stack *stack, void *data)
{
	t_list	*new_node;

	if (!stack)
		return (0);
	if (stack_is_full(stack))
		stack = stack_grow(stack);
	new_node = list_pop_at(&stack->free_node, 0);
	new_node->data = data;
	list_push_at(&stack->top, new_node, 0);
	stack->count += 1;
	return (data);
}
