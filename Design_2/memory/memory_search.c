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

#include "../plib.h"

void	*memory_search(void *m1, int ch, unsigned int n)
{
	unsigned char	*ptr_m1;

	if (!m1 || !n)
		return (0);
	ptr_m1 = m1;
	while (n--)
	{
		if (*ptr_m1 == ch)
			return ((void *)ptr_m1);
		++ptr_m1;
	}
	return (0);
}
