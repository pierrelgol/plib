/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_peek.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 21:05:18 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/05 21:05:20 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

void	*stack_peek(t_stack *stack)
{
	if (!stack || stack_is_empty(stack))
		return (0);
	return (stack->top->data);
}
