/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_search.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 12:08:04 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/01 12:08:05 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/plib.h"


void	*memory_search(void *m1, char ch, size_t n)
{
	unsigned char	*ptr_m1;

	if (DBG == 2)
		print_fmt("[LOG]memory_compare(%p, %c, %u)\n",m1,ch,n);
	ptr_m1 = m1;
	while (n--)
	{
		if (*ptr_m1 == ch)
			return ((void *)ptr_m1);
		++ptr_m1;
	}
	return (0);
}
