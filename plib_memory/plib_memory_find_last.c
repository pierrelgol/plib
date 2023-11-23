/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plib_memory_find_last.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 11:34:14 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/11/23 11:34:15 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

void	*plib_memory_find_last(void *src, int ch, unsigned int srchsize)
{
	unsigned char	*ptr_end;
	unsigned char	*ptr_s;
	unsigned char	*ptr_ch;

	ptr_ch = NULL;
	ptr_s = (unsigned char *)src;
	ptr_end = (unsigned char *)src + srchsize;
	while (ptr_s < ptr_end)
	{
		if (*ptr_s == ch)
			ptr_ch = ptr_s;
		++ptr_s;
	}
	return (ptr_ch);
}
