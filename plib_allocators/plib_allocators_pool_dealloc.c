/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plib_allocators_pool_dealloc.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 16:20:54 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/11/28 16:20:55 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

void plib_allocators_pool_dealloc(t_pool *self, void *ptr)
{
	t_list *pool;

	if (!self || !ptr)
		return;
	pool = ptr - sizeof(t_list);
	pool->next = self->memory_list;
	self->memory_list = pool;
}
