/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plib_allocators_pool_alloc.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 16:07:58 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/11/28 16:07:58 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

void *plib_allocators_pool_alloc(t_pool *pool)
{
	t_list *next_pool;

	if (!pool || !pool->memory_list)
		return (NULL);
	next_pool = pool->memory_list;
	pool->memory_list = next_pool->next;
	return ((void*)next_pool + sizeof(t_list));
}
