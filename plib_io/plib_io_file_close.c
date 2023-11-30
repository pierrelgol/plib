/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plib_io_file_close.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 12:31:38 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/11/28 12:31:40 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

int plib_io_file_close(t_file *self)
{
	if (self->status & IS_OPEN)
	{
		self->status ^= (IS_OPEN | IS_VALID);
		self->fd = close(self->fd);
	}
	return (self->fd);
}
