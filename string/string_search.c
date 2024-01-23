/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_search.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 21:31:23 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/10 21:31:25 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

char	*string_preprocess(char *lookup, char *pat, int plen)
{
	int	c;
	int	j;

	c = 0;
	j = 0;
	while (c < 256)
		lookup[c++] = -1;
	while (j < plen)
	{
		lookup[(int)pat[j]] = j;
		++j;
	}
	return (lookup);
}

char	*string_search(char *string, char *pat, int slen, int plen)
{
	char	*lookup;
	int		skip;
	int		i;
	int		j;

	i = 0;
	lookup = string_preprocess((char [256]){0}, pat, plen);
	while (i <= (slen - plen))
	{
		skip = 0;
		j = plen;
		while (--j >= 0)
		{
			if (pat[j] != string[i + j])
			{
				skip = j - lookup[(int)string[i + j]];
				skip = (skip < 1) * 1 + (skip >= 1) * skip;
				break ;
			}
		}
		if (skip == 0)
			return (&string[i]);
		i += skip;
	}
	return (0);
}

// char *string_search(char *str, char *sub)
// {
// 	unsigned int i;
// 	unsigned int j;
// 	unsigned int slen;

// 	if (!str || !sub)
// 		return (0);
// 	slen = string_length(str);
// 	if (!*sub)
// 		return ((char *) str);
// 	i = 0;
// 	while (str[i])
// 	{
// 		j = 0;
// 		while (str[i] && str[i] == sub[j] && i < slen)
// 		{
// 			j++;
// 			i++;
// 		}
// 		if (!sub[j])
// 			return ((char *) &str[(unsigned int) i - j]);
// 		i = (i - j) + 1;
// 	}
// 	return (0);
// }
