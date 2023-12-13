/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_alloc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 11:47:02 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/01 11:47:05 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

void	*memory_alloc(unsigned int count, unsigned int size)
{
	unsigned int	allocation_size;
	void			*memory;

	allocation_size = (count * size);
	if (!allocation_size || allocation_size >= 2147483647)
		return (0);
	memory = malloc(allocation_size);
	if (!memory)
		return (0);
	return (memory_set(memory, 0x00, allocation_size));
}
