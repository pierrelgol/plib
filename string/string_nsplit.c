/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_nsplit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 12:51:51 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/01 12:51:52 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

char	**string_nsplit(char *str, unsigned int n)
{
	char			**split;
	unsigned int	nchunk;
	unsigned int	slen;
	unsigned int	pad;
	unsigned int	i;

	if (!str || !n)
		return (0);
	slen = string_length(str);
	pad = 0;
	if ((slen + pad) % n != 0)
	{
		while ((slen + pad) % n != 0)
			++pad;
		str = string_pad_right(str, '0', pad + 1);
	}
	nchunk = (slen + pad) / n;
	split = string_split_create(nchunk);
	i = 0;
	while (i < nchunk)
	{
		split[i] = string_create(n + 1);
		if (!split[i])
			string_split_destroy(split, i);
		memory_copy(split[i], &str[i * n], n);
		++i;
	}
	return (split);
}
