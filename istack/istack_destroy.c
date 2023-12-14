/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   istack_destroy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 15:56:56 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/14 15:56:57 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

t_istack	*istack_destroy(t_istack *stack)
{
	if (!stack)
		return (0);
	if (stack->data != 0)
		memory_destroy(stack->data);
	return (memory_destroy(stack));
}
