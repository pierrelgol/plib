/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plib_writer_create.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 13:06:44 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/11/23 14:26:23 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

t_writer	*plib_writer_create(char *buffer, int size, int fd)
{
	t_writer	*self;

	self = plib_memory_alloc(1, sizeof(t_writer));
	if (!self)
		return (NULL);
	self->buffer = buffer;
	self->bsize = size;
	self->fd = fd;
	return (self);
}
