/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_destroy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 11:04:38 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/09 11:04:39 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/plib.h"

t_file	*file_destroy(t_file *file)
{
	struct s_allocator *allocator;

	if (!file)
		return (0);
	allocator = file->allocator;
	if (bit_is_set(file->flag, IS_OPEN))
		file_close(file->in);
	if (file->name)
		string_destroy(allocator ,file->name);
	if (file->path)
		string_destroy(allocator ,file->path);
	if (file->content)
		string_destroy(allocator ,file->content);
	if (file->buffer)
		buffer_destroy(file->buffer);
	return (allocator->destroy(allocator, file));
}
