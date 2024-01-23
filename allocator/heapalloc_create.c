/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heapalloc_create.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 10:42:52 by pollivie          #+#    #+#             */
/*   Updated: 2024/01/23 10:42:52 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

void *heapalloc_create(struct s_allocator *self, size_t size)
{
	if (!self)
		return (0);
	return (memory_create(1, size));
}

