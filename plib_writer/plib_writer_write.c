/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plib_writer_write.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 13:09:48 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/11/23 14:26:41 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

int	plib_writer_write(t_writer *self, int size)
{
	int	written;

	if (size > (self->bsize - self->bcount))
		size = self->bsize - self->bcount;
	written = write(self->fd, &self->buffer[self->bcount], size);
	self->bcount += size;
	return (written);
}
