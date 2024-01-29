/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap_destroy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 10:42:10 by pollivie          #+#    #+#             */
/*   Updated: 2024/01/23 10:42:11 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/plib.h"

void *heap_destroy(struct s_allocator *self, void *ptr)
{
	if (!ptr)
		return (0);
	(void)self;
	return (memory_destroy(ptr));
}
