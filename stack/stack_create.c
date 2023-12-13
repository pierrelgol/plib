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
	t_stack	*stack;

	stack = memory_create(1, sizeof(t_stack));
	if (!stack)
		return (0);
	stack->top = list_create();
	stack->top->data = 0;
	stack->free_node = 0;
	stack->size = 1;
	stack->count = 0;
	return (stack);
}
