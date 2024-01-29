/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena_realloc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 11:27:18 by pollivie          #+#    #+#             */
/*   Updated: 2024/01/23 11:27:20 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/plib.h"

void *arena_realloc(struct s_allocator *self, void *ptr, size_t prev, size_t next)
{
	void *new_ptr;

	if (prev >= next)
		return (ptr);
	new_ptr = self->create(self, next + 1);
	memory_copy(new_ptr,ptr, prev);
	return (new_ptr);
}
