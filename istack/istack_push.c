/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   istack_push.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 15:57:26 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/14 15:57:26 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

void	istack_push(t_istack *stack, int value)
{
	if (stack->count == stack->capacity - 1)
		return ;
	stack->data[++stack->count] = value;
}
