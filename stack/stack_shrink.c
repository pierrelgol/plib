/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_shrink.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 11:29:20 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/08 11:29:22 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

t_stack	*stack_shrink(t_stack *stack)
{
	unsigned int	current_size;
	unsigned int	target_size;

	if (!stack)
		return (0);
	current_size = stack->size;
	target_size = current_size >> 1;
	if (current_size >= 2)
	{
		while (current_size > target_size)
		{
			list_remove_front(&stack->free_node);
			--current_size;
		}
		stack->size = target_size;
	}
	return (stack);
}
