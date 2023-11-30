/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plib_memory_move.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 11:34:44 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/11/23 11:34:44 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

void	*plib_memory_move(void *dst, void *src, unsigned int mov_size)
{
	const char	*ptr_src;
	char		*ptr_dst;

	if (!dst || !src)
		return (NULL);
	ptr_src = (const char *)src;
	ptr_dst = (char *)dst;
	if (dst > src)
	{
		while (mov_size)
		{
			*(ptr_dst + mov_size - 1) = *(ptr_src + mov_size - 1);
			mov_size--;
		}
		return (dst);
	}
	while (mov_size--)
		*ptr_dst++ = *ptr_src++;
	return (dst);
}
