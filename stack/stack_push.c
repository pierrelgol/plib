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

void	*stack_push(t_stack *stack, void *data)
{
	t_list	*new;

	if (!stack)
		return (0);
	if (stack_is_full(stack))
		stack = stack_grow(stack);
	new = list_pop_front(&stack->free_node);
	new->data = data;
	list_push_front(&stack->top, new);
	stack->count += 1;
	return (data);
}
