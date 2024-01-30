/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_copy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 12:03:47 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/01 12:03:48 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/plib.h"


void	*memory_copy(void *dst, void *src, size_t n)
{
	char	*pdst;
	char	*psrc;

	if (DBG == 2)
		print_fmt("[LOG]memory_copy(%p, %p, %u)\n",dst,src,n);
	pdst = dst;
	psrc = src;
	while (n > 0)
	{
		*pdst++ = *psrc++;
		--n;
	}
	return (dst);
}
