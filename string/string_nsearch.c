/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_nsearch.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 12:48:20 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/01 12:48:21 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

char	*string_nsearch(char *str, char *sub, unsigned int n)
{
	unsigned int	i;
	unsigned int	j;

	if (!str || !sub || n == 0)
		return (0);
	if (!*sub)
		return ((char *)str);
	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i] && str[i] == sub[j] && i < n)
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
