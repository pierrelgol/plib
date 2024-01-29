/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 10:44:50 by pollivie          #+#    #+#             */
/*   Updated: 2024/01/23 10:44:51 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/plib.h"

struct s_allocator *arena_init(struct s_allocator *parent_allocator, size_t size)
{
	struct s_allocator *arena;

	arena = parent_allocator->create(parent_allocator, sizeof(struct s_allocator));
	if (!arena)
		return (0);
	arena->next = 0;
	arena->is_arena = true;
	arena->count = 0;
	arena->capacity = size;
	arena->parent_allocator = parent_allocator;
	arena->region = parent_allocator->create(parent_allocator, size * sizeof(char));
	arena->create = arena_create;
	arena->destroy = arena_destroy;
	arena->realloc = arena_realloc;
	return (arena);
}
