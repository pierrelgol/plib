/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_create.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 19:59:26 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/04 19:59:29 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

t_list	*list_create(void)
{
	t_list	*self;

	self = memory_create(1, sizeof(*self));
	if (!self)
		return (0);
	self->next = 0;
	self->data = 0;
	return (self);
}
