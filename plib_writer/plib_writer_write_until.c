/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plib_writer_write_until.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 13:23:05 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/11/23 14:26:46 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

int	plib_writer_write_until(t_writer *self, int delimiter)
{
	int	written;
	int	size;

	size = plib_string_index_of(&self->buffer[self->bcount], delimiter);
	if (size == -1)
		return (-1);
	if (size > (self->bsize - self->bcount))
		size = self->bsize - self->bcount;
	written = write(self->fd, &self->buffer[self->bcount], size);
	self->bcount += size;
	return (written);
}
