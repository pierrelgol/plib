/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plib_io_file_attach_buffer.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 13:24:58 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/11/28 13:27:05 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

int	plib_io_file_attach_buffer(t_file *self, char *buffer, int bsize)
{
	if (!self->content)
	{
		self->content = buffer;
		self->size = bsize;
	}
	else
	{
		if (self->status & IS_FREEABLE_BUFFER)
		{
			plib_memory_dealloc(self->content);
			self->status ^= IS_FREEABLE_BUFFER;
		}
		self->size = bsize;
		self->content = buffer;
	}
	return (self->size);
}
