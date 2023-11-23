/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plib_reader_read_until.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 13:31:49 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/11/23 13:31:50 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

int	plib_reader_read_until(t_reader *self, int delimiter)
{
	int	read_from;

	read_from = 0;
	while (self->bcount < self->bsize)
	{
		read_from += read(self->fd, &self->buffer[self->bcount], 1);
		if (self->buffer[self->bcount++] == delimiter)
			return (read_from);
	}
	return (-1);
}
