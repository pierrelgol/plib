/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena_deinit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 10:49:08 by pollivie          #+#    #+#             */
/*   Updated: 2024/01/23 10:49:08 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

static void *arena_deinit_child(struct s_allocator *parent, struct s_allocator *child)
{
	if (child != 0)
	{
		parent->destroy(parent, child->region);
		parent->destroy(parent, child);
	}
	return (0);
}

void *arena_deinit(struct s_allocator *self)
{
	struct s_allocator *parent;
	struct s_allocator *child;
	struct s_list *list;
	struct s_list *temp;

	if (!self)
		return (0);
	parent = self->parent_allocator;
	list = self->next;
	while (list)
	{
		temp = list_pop_at(&list, 0);
		list = list->next;
		child = temp->data;
		parent->destroy(parent, temp);
		arena_deinit_child(parent, child);
	}
	parent->destroy(parent, self->region);
	return (parent->destroy(parent, self));
}

