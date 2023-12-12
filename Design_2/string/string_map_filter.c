/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_map_filter.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 12:48:53 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/01 12:48:54 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

char	*string_map_filter(char *str, int (*f)(int ch))
{
	char			*result;
	unsigned int	rlength;
	unsigned int	i;

	if (!str || !f)
		return (0);
	rlength = string_length(str) - (unsigned int)string_map_count(str, f);
	result = string_create(rlength + 1);
	if (!result)
		return (0);
	i = 0;
	while (*str)
	{
		if (!f(*str))
			result[i++] = *str;
		++str;
	}
	return (result);
}
