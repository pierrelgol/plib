/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_split_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 12:52:15 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/01 12:52:16 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

char	*string_map_split_create(char *str, int (*f)(int ch))
{
	char			*result;
	unsigned int	i;

	i = 0;
	while (f(str[i]))
		++i;
	result = memory_alloc(i + 1, sizeof(char));
	memory_copy(result, str, i);
	return (result);
}

char	**string_map_split(char *str, int (*f)(int ch))
{
	char			**result;
	unsigned int	length;
	unsigned int	index;

	if (!str || !f)
		return (0);
	index = 0;
	length = (unsigned int)string_map_count(str, f);
	result = string_split_create(length + 1);
	while (index < length)
	{
		while (*str && f(*str))
			++str;
		if (*str && !f(*str))
			result[index] = string_map_split_create(str, f);
		if (!result[index++])
			return (string_split_destroy(result, index - 1));
		while (*str && !f(*str))
			++str;
	}
	return (result);
}
