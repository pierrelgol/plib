/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_create.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 10:43:40 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/09 10:43:41 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/plib.h"

t_file	*file_create(struct s_allocator *allocator)
{
	t_file	*file;

	file = allocator->create(allocator, sizeof(t_file));
	if (!file)
		return (0);
	if (allocator->is_logger)
		file->allocator = allocator->parent_allocator;
	else
		file->allocator = allocator;
	file->flag = bit_set_bit(file->flag, IS_VALID);
	return (file);
}
