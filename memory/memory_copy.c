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

#include "../plib.h"

void	*memory_copy(void *dest, void *src, unsigned int n)
{
	char	*pdest;
	char	*psrc;

	if (!dest || !src || !n)
		return (0);
	pdest = dest;
	psrc = src;
	while (n--)
		*pdest++ = *psrc++;
	return (dest);
}
