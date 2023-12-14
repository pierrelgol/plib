/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   istack_pop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 15:57:20 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/14 15:57:21 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

int	istack_pop(t_istack *stack)
{
	if (istack_is_empty(stack))
		return (-2147483648);
	return (stack->data[stack->count--]);
}
