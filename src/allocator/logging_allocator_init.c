/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logging_allocator_init.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 13:12:16 by pollivie          #+#    #+#             */
/*   Updated: 2024/01/30 13:12:18 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/plib.h"

struct s_allocator *logging_allocator_init(struct s_allocator *parent)
{
	struct	s_allocator *logging;
	struct s_allocator *private;

	private = heap_init();
	logging = private->create(parent, sizeof(struct s_allocator));
	if (!logging)
		return (0);
	logging->private_allocator = private;
	logging->parent_allocator = parent;
	logging->create = logging_allocator_create;
	logging->destroy = logging_allocator_destroy;
	logging->realloc = logging_allocator_realloc;
	logging->capacity = 16384;
	logging->history = private->create(private, 16384);
	logging->history = list_create(private);
	return (logging);

}
