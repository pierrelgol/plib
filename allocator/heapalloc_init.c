/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heapalloc_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 10:22:36 by pollivie          #+#    #+#             */
/*   Updated: 2024/01/23 10:22:36 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

struct s_allocator *heapalloc_init(void)
{
	struct s_allocator *heapalloc;

	heapalloc = memory_create(1, sizeof(struct s_allocator));
	if (!heapalloc)
		return (0);
	heapalloc->is_heap = true;
	heapalloc->log_info = LOG;
	heapalloc->logger = print_fmt;
	heapalloc->create = heapalloc_create;
	heapalloc->destroy = heapalloc_destroy;
	heapalloc->realloc = heapalloc_realloc;
	return (heapalloc);
}
