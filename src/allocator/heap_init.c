/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 10:22:36 by pollivie          #+#    #+#             */
/*   Updated: 2024/01/23 10:22:36 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/plib.h"

struct s_allocator *heap_init(void)
{
	struct s_allocator *heap;

	heap = memory_create(1, sizeof(struct s_allocator));
	if (!heap)
		return (0);
	heap->is_heap = true;
	heap->create = heap_create;
	heap->destroy = heap_destroy;
	heap->realloc = heap_realloc;
	return (heap);
}
