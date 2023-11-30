/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plib_memory_copy.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 11:34:36 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/11/23 11:34:36 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

void	*plib_memory_copy(void *dst, void *src, unsigned int movsize)
{
	char			*ptr_src;
	char			*ptr_dst;
	unsigned int	i;

	if (!dst || !src)
		return (NULL);
	i = 0;
	ptr_dst = dst;
	ptr_src = src;
	while (i < movsize)
	{
		*ptr_dst++ = *ptr_src++;
		++i;
	}
	return (dst);
}
