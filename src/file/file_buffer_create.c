/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_buffer_create.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 16:48:51 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/30 16:48:52 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../include/plib.h"

int	file_buffer_create(t_file *file)
{
	struct s_allocator *allocator;

	allocator = file->allocator;
	file->buffer = buffer_create(allocator);
	if (!file->buffer)
		return (0);
	return (1);
}

