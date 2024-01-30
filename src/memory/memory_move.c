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

#include "../../include/plib.h"


void	*memory_move(void *dst, void *src, size_t n)
{
	const char	*ptr_src;
	char		*ptr_dst;

	if (DBG)
		print_fmt("[LOG]memory_compare(%p, %p, %u)\n",dst,src,n);
	if (dst == src)
		return (dst);
	ptr_src = (char *)src;
	ptr_dst = (char *)dst;
	if (dst > src)
	{
		while (n > 0)
		{
			*(ptr_dst + n - 1) = *(ptr_src + n - 1);
			--n;
		}
		return (dst);
	}
	while (n-- > 0)
		*ptr_dst++ = *ptr_src++;
	return (dst);
}
