/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plib_io_file_create.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 13:24:28 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/11/28 13:24:29 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

t_file *plib_io_file_create(int type)
{
	t_file	*self;

	self = plib_memory_alloc(1, sizeof(t_file));
	if (!self)
		return (NULL);
	self->status |= (IS_VALID | type);
	return (self);
}

