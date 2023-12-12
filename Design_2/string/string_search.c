/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_search.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 12:47:53 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/01 12:47:54 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

char	*string_search(char *str, char *sub)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	s;

	if (!str || !sub)
		return (0);
	s = string_length(str);
	if (!*sub)
		return ((char *)str);
	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i] && str[i] == sub[j] && i < s)
		{
			j++;
			i++;
		}
		if (!sub[j])
			return ((char *)&str[(unsigned int)i - j]);
		i = (i - j) + 1;
	}
	return (0);
}
