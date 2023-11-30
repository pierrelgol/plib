/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plib_io_file_write.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 13:24:14 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/11/28 13:24:15 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

int plib_io_file_write(t_file *self, int rbyte, int fd)
{
	int w;

	if (rbyte <= 0)
		return (-1);
	if (rbyte > self->count)
		rbyte = self->count;
	w = write(fd, &self->content[self->count - rbyte], rbyte);
	self->count -= w;
	return (w);
}
