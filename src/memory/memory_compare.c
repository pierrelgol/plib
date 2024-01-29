/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_compare.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 11:55:34 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/01 11:55:36 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/plib.h"

int	memory_compare(const void *m1, const void *m2, size_t n)
{
	const unsigned char	*p1;
	const unsigned char	*p2;

	if (DBG)
		print_fmt("[LOG]memory_compare(%p, %p, %d)\n",m1,m2,n);
	p1 = (unsigned char *)m1;
	p2 = (unsigned char *)m2;
	while (n--)
	{
		if (*p1 != *p2)
			return (*p1 - *p2);
		++p1;
		++p2;
	}
	return (0);
}
