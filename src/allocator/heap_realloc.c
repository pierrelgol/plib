/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap_realloc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 10:43:58 by pollivie          #+#    #+#             */
/*   Updated: 2024/01/23 10:43:58 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/plib.h"

void *heap_realloc(struct s_allocator *self, void *ptr, size_t prev, size_t next)
{
	if (!self)
		return (0);
	if (prev >= next)
		return (ptr);
	return (memory_realloc(ptr, prev, next));
}


