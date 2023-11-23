/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plib_reader_open.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 13:31:23 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/11/23 13:31:24 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

int	plib_reader_open(t_reader *self, char *path, unsigned int flags)
{
	self->flags = flags;
	self->fd = open(path, flags);
	return (self->fd);
}
