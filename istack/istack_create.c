/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   istack_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 15:56:50 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/14 15:56:51 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

t_istack	*istack_create(unsigned int size)
{
	t_istack	*stack;

	stack = memory_create(1, sizeof(t_istack));
	if (!stack)
		return (0);
	stack->capacity = size;
	stack->count = -1;
	stack->data = memory_create(size, sizeof(int));
	if (!stack->data)
		return (istack_destroy(stack));
	return (stack);
}
