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

int	plib_string_concat(char *dst, char *src)
{
	unsigned int	dlen;
	unsigned int	slen;

	slen = 0;
	dlen = plib_string_length(dst);
	while (src[slen])
		dst[dlen++] = src[slen++];
	return (slen + dlen);
}
