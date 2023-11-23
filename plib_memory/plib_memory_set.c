/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plib_memory_set.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 11:33:51 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/11/23 11:33:53 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

void	*plib_memory_set(void *str, int ch, unsigned int setsize)
{
	unsigned char	*ptr_str;
	unsigned char	*ptr_end;

	ptr_str = (unsigned char *)str;
	ptr_end = (unsigned char *)str + setsize;
	while (ptr_str < ptr_end)
		*ptr_str++ = (unsigned char)ch;
	return (str);
}
