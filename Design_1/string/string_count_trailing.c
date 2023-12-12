/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_count_trailing_char.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 16:38:46 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/10 16:38:47 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

unsigned int	string_count_trailing(char *src, int ch)
{
	unsigned int	count;
	unsigned int	slen;

	if (!src)
		return (0);
	count = 0;
	slen = string_length(src);
	if (slen == 0)
		return (0);
	while (slen >= 1 && src[slen - 1] == ch)
	{
		--slen;
		++count;
	}
	return (count);
}
