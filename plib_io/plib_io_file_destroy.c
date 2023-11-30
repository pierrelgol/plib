/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plib_io_file_destroy.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 12:21:10 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/11/28 13:24:40 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

t_file	*plib_io_file_destroy(t_file *self)
{
	if (self->status & IS_OPEN)
		plib_io_file_close(self);
	else
	{
		if (self->status & IS_FREEABLE_BUFFER)
			plib_memory_dealloc(self->content);
		plib_memory_dealloc(self);
	}
	return (NULL);
}
