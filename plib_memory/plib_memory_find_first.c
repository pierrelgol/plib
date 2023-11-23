/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plib_memory_find_first.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 11:34:02 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/11/23 11:34:03 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

void	*plib_memory_find_first(void *src, int ch, unsigned int srchsize)
{
	unsigned char	*ptr_end;
	unsigned char	*ptr_s;

	ptr_s = (unsigned char *)src;
	ptr_end = (unsigned char *)src + srchsize;
	while (ptr_s < ptr_end && *ptr_s != (unsigned char)ch)
		++ptr_s;
	if (ptr_s == ptr_end)
		return (NULL);
	return ((void *)ptr_s);
}
