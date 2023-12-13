/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 13:56:51 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/01 13:56:52 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

void	*memory_move(void *dst, const void *src, unsigned int len)
{
	const char	*ptr_src;
	char		*ptr_dst;

	if (!dst || !src)
		return (0);
	ptr_src = (const char *)src;
	ptr_dst = (char *)dst;
	if (dst > src)
	{
		while (len)
		{
			*(ptr_dst + len - 1) = *(ptr_src + len - 1);
			len--;
		}
		return (dst);
	}
	while (len--)
		*ptr_dst++ = *ptr_src++;
	return (dst);
}
