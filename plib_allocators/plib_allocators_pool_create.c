/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plib_allocators_pool_create.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 15:54:17 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/11/28 15:54:33 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

t_pool *plib_allocators_pool_create(unsigned long npool, unsigned long pool_size)
{
	t_pool       *pool;
	t_list       *next_pool;
	void         *memory;
	unsigned long i;
	unsigned long size;

	i = 0;
	size = npool * (sizeof(struct s_list) + pool_size);
	memory = plib_memory_alloc(size, sizeof(t_pool));
	if (!memory)
		return (NULL);
	pool = memory;
	pool->memory_list = NULL;
	memory += sizeof(t_pool);
	while (i < npool)
	{
		next_pool = memory + i * (pool_size + sizeof(t_pool));
		next_pool->next = pool->memory_list;
		pool->memory_list = next_pool;
		++i;
	}

	return pool;
}
