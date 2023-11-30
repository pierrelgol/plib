/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plib_io_file_erase.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 14:30:03 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/11/28 14:30:04 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

t_file *plib_io_file_erase_content(t_file *self)
{
	self->content = plib_memory_set(self->content, 0x00, self->size);
	self->count = 0;
	return (self);
}
