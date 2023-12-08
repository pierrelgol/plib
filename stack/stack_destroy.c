/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_destroy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 21:04:47 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/05 21:04:50 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

t_stack	*stack_destroy(t_stack *self)
{
	if (!self)
		return (0);
	if (self->stack)
		list_destroy(self->stack);
	return (memory_dealloc(self));
}
