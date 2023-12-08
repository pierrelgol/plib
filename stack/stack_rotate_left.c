/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_rotate_left.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 21:05:52 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/05 21:05:53 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

t_stack     *stack_rotate_left(t_stack *stack, unsigned int n)
{
	if (!stack || stack_is_empty(stack))
		return (0);
	stack->top = list_rotate_left(&stack->top, n);
	return (stack);
}

