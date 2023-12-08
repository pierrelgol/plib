/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_clear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 21:06:02 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/05 21:06:04 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

void	stack_clear(t_stack *stack)
{
	t_list *temp;

	if (!stack)
		return;
	while (stack->count != 0)
	{
		temp = list_pop_front(&stack->top);
		temp->data = 0;
		list_push_front(&stack->free_node, temp);
		stack->count -= 1;
	}
}
