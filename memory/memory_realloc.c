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

#include "../plib.h"

void	*memory_realloc(void *ptr, size_t old_size, size_t size)
{
	void	*new_ptr;

	new_ptr = memory_create(size, 1);
	if (!new_ptr)
		return (ptr);
	memory_copy(new_ptr, ptr, old_size);
	memory_destroy(ptr);
	return (new_ptr);
}
