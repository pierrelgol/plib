/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plib_reader_read.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 13:31:41 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/11/23 13:31:42 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

int	plib_reader_read(t_reader *self, int size)
{
	int	read_from;

	if (self->bcount + size > self->bsize)
		size = self->bsize - self->bcount;
	read_from = read(self->fd, &self->buffer[self->bcount], size);
	self->bcount += size;
	return (read_from);
}
