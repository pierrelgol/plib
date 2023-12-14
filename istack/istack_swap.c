/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   istack_swap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 15:57:32 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/14 15:57:32 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

void	istack_swap(t_istack *stack)
{
	int	temp;

	if (stack->count < 2)
		return ;
	temp = stack->data[stack->count];
	stack->data[stack->count] = stack->data[stack->count - 1];
	stack->data[stack->count - 1] = temp;
}
