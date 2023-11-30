/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plib_io_file_open.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 12:31:32 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/11/28 12:31:33 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

int	plib_io_file_open(t_file *self, char *path, int perm)
{
	if (self->status & (IS_OPEN))
		plib_io_file_close(self);
	self->path = path;
	self->perm = perm;
	self->fd = open(path, perm);
	if (self->fd >= 0)
		self->status ^= (IS_OPEN & IS_VALID); 
	return (self->fd);
}
