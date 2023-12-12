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

#include "../plib.h"

int	memory_compare(void *m1, void *m2, unsigned int n)
{
	const unsigned char	*p1;
	const unsigned char	*p2;

	if (!m1 || !m2 || !n)
		return (0);
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
