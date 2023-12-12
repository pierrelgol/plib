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

void	*memory_move(void *dst, void *src, unsigned int n)
{
	const char	*ptr_src;
	char		*ptr_dst;

	if (!dst || !src)
		return (0);
	ptr_src = (char *)src;
	ptr_dst = (char *)dst;
	if (dst > src)
	{
		while (n)
		{
			*(ptr_dst + n - 1) = *(ptr_src + n - 1);
			n--;
		}
		return (dst);
	}
	while (n--)
		*ptr_dst++ = *ptr_src++;
	return (dst);
}
