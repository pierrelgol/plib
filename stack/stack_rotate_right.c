/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 21:05:26 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/05 21:05:27 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

t_stack     *stack_rotate_right(t_stack *stack, unsigned int n)
{
	if (!stack || stack_is_empty(stack))
		return (0);
	stack->top = list_rotate_right(&stack->top, n);
	return (stack);
}


