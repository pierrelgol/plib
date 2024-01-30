/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 11:47:02 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/01 11:47:05 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/plib.h"


void	*memory_create(size_t count, size_t size)
{
	void			*memory;

	if (DBG)
		print_fmt("[LOG]memory_create(%u, %u)\n",count,size);
	if (count * size == 0)
		return (0);
	memory = malloc(count * size);
	if (!memory)
		return (0);
	return (memory_set(memory, 0x00, count * size));
}

// void	*dbg_memory_create(char *caller, size_t count, size_t size)
// {
// 	void			*memory;

// 	print_fmt("caller : %s count : %d size : %d\n",caller, count, size);
// 	memory = malloc(count * size);
// 	if (!memory)
// 		return (0);
// 	return (memory_set(memory, 0x00, count * size));
// }
