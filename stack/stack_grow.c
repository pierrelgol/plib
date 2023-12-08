/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_grow.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 11:23:36 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/08 11:23:37 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

t_stack *stack_grow(t_stack *stack)
{
	unsigned int i;

	if (!stack)
		return (0);
	i = 0;
	while (i < (stack->size << 1))
	{
		list_insert_front(&stack->free_node, 0);
		++i;
	}
	stack->size <<= 1;
	return (stack);
}
