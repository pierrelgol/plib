/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plib_string_substring_find.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 09:38:09 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/11/23 10:40:51 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

char	*plib_string_substring_find(char *str, char *sub, unsigned int srchsize)
{
	unsigned int	i;
	unsigned int	j;

	if (!str && srchsize == 0)
		return (NULL);
	if (!*sub)
		return ((char *)str);
	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i] && str[i] == sub[j] && i < srchsize)
		{
			j++;
			i++;
		}
		if (!sub[j])
			return ((char *)&str[(int)i - j]);
		i = (i - j) + 1;
	}
	return (NULL);
}
