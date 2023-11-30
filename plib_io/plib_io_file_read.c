/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plib_io_file_read.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 13:24:08 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/11/28 13:24:09 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

int     plib_io_file_read(t_file *self, int rbyte, int fd)
{
	int	r;

	if ((self->count + rbyte) >= self->size)
		rbyte = self->size - self->count;
	r = read(fd, &self->content[self->count], rbyte);
	self->count += r;
	return (r);
}
