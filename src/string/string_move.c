/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 20:29:13 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/10 20:29:14 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/plib.h"

char	*string_move(char *dst, char *src, unsigned int n)
{
	char	*psrc;
	char	*pdst;

	if (!dst || !src)
		return (0);
	psrc = src;
	pdst = dst;
	if (dst > src)
	{
		while (n)
		{
			*(pdst + n - 1) = *(psrc + n - 1);
			n--;
		}
		return (dst);
	}
	while (n--)
		*pdst++ = *psrc++;
	return (dst);
}
