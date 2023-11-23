/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plib_reader_create.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 13:31:03 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/11/23 13:31:04 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

t_reader	*plib_reader_create(char *buffer, int size)
{
	t_reader	*self;

	self = plib_memory_alloc(1, sizeof(t_reader));
	if (!self)
		return (NULL);
	self->buffer = buffer;
	self->bsize = size;
	return (self);
}
