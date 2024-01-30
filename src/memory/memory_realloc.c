/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_realloc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 17:47:00 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/29 17:47:01 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/plib.h"


void	*memory_realloc(void *ptr, size_t prev, size_t next)
{
	void	*new_ptr;

	if (DBG)
		print_fmt("[LOG]memory_compare(%p, %u, %u)\n",ptr,prev,next);
	if (prev == next)
		return (ptr);
	new_ptr = memory_create(next, 1);
	if (!new_ptr)
		return (0);
	memory_copy(new_ptr, ptr, prev);
	memory_destroy(ptr);
	return (new_ptr);
}
