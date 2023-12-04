/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_node_create.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 11:09:57 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/04 11:09:58 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

t_node	*list_node_create(void *data)
{
	t_node	*self;

	self = memory_alloc(1, sizeof(t_node));
	if (!self)
		return (0);
	self->data = data;
	self->next = 0;
	self->prev = 0;
	return (self);
}
