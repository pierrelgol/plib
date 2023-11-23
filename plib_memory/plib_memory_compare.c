/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plib_memory_compare.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 11:34:23 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/11/23 11:34:24 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

int	plib_memory_compare(void *src1, void *src2, unsigned int cmpsize)
{
	unsigned char	*ptr_s1;
	unsigned char	*ptr_s2;

	if (cmpsize == 0)
		return (0);
	ptr_s1 = (unsigned char *)src1;
	ptr_s2 = (unsigned char *)src2;
	while (--cmpsize && *ptr_s1 == *ptr_s2)
	{
		++ptr_s1;
		++ptr_s2;
	}
	return (*ptr_s1 - *ptr_s2);
}
