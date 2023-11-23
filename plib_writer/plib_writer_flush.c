/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plib_writer_flush.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 13:28:32 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/11/23 14:26:34 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

int	plib_writer_flush(t_writer *self)
{
	return (write(self->fd, &self->buffer[self->bcount], self->bsize));
}
