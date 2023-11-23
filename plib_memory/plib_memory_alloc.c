/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plib_memory_alloc.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 11:33:30 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/11/23 11:33:32 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

void	*plib_memory_alloc(unsigned int count, unsigned int size)
{
	void	*ptr;

	ptr = malloc(count * size);
	if (!ptr)
		return (NULL);
	return (plib_memory_set(ptr, 0, count * size));
}
