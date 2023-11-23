/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plib_string_concat.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 10:13:27 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/11/23 10:13:28 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

int	plib_string_concat(char *dst, char *src, unsigned int dstsize)
{
	unsigned int	dlen;
	unsigned int	slen;

	if (dstsize == 0)
		return (0);
	slen = 0;
	dlen = plib_string_length(dst);
	while (src[slen] && (dlen + slen) < dstsize - 1)
		dst[dlen++] = src[slen++];
	dst[dlen] = '\0';
	return (slen + dlen);
}
