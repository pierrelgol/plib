/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plib_io_file_create_buffer.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 13:24:52 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/11/28 13:27:12 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

int plib_io_file_create_buffer(t_file *self, int size)
{
	if (self->content && self->status & IS_FREEABLE_BUFFER)
		plib_memory_dealloc(self->content);
	self->content = plib_memory_alloc(size, sizeof(char));
	if (!self->content)
		self->status ^= (IS_VALID | IS_FREEABLE_BUFFER);
	else
	{
		self->size = size;		
		self->status |= (IS_VALID | IS_FREEABLE_BUFFER);
	}
	return (size);
}
