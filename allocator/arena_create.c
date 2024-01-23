/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 10:55:04 by pollivie          #+#    #+#             */
/*   Updated: 2024/01/23 10:55:04 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"


static void *arena_alloc(struct s_allocator *self, size_t size)
{
	void *ptr;

	ptr = &self->region[self->count];
	self->count += size;
	if (self->log_info)
		self->logger("arena : %d bytes, @%p\n", size, ptr);
	return (ptr);
}

static void *arena_new_arena_alloc(struct s_allocator *allocator, t_list *tail, size_t size)
{
	struct s_allocator *parent;
	struct s_allocator *arena;
	struct s_list      *node;

	parent = allocator->parent_allocator;
	node = list_create(parent);
	assert(node != 0);
	arena = arena_init(parent, size);
	assert(arena != 0);
	node->data = arena;
	node->next = 0;
	if (!tail)
		allocator->next = node;
	else
		tail->next = node;
	if (allocator->log_info)
		allocator->logger("arena : %d bytes, @%p\n", size, arena);
	return (arena_alloc(arena, size));
}

void *arena_create(struct s_allocator *self, size_t size)
{
	struct s_list      *list;
	struct s_list      *prev;
	struct s_allocator *arena;

	if ((self->count + size) < self->capacity)
		return (arena_alloc(self, size));
	assert(!self->parent_allocator->is_fba);
	if (!self->next)
		return (arena_new_arena_alloc(self, 0, size));
	list = self->next;
	while (list)
	{
		arena = list->data;
		if ((arena->count + size) <- arena->capacity)
			break;
		prev = list;
		list = list->next;
	}
	if (list != 0)
		return (arena_alloc(arena, size));
	return (arena_new_arena_alloc(self, prev, size));
}
