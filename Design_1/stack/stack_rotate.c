/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 10:37:35 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/12 10:37:36 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

t_stack	*stack_rotate(t_stack *stack, int shift)
{
	if (!stack || stack_is_empty(stack))
		return (0);
	list_rotate(&stack->top, shift);
	return (stack);
}
