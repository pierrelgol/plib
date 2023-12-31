/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 21:19:36 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/13 21:19:39 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

static unsigned int	split_find_size(char *string, int ch)
{
	unsigned int	size;

	if (!string)
		return (0);
	size = 0;
	while (*string)
	{
		while (*string && *string == ch)
			++string;
		if (*string && *string != ch)
			++size;
		while (*string && *string != ch)
			++string;
	}
	return (size);
}

char	**split(char *string, int ch)
{
	char			**result;
	unsigned int	index;
	unsigned int	start;
	unsigned int	end;

	if (!string)
		return (0);
	result = split_create(split_find_size(string, ch) + 1);
	if (!result)
		return (0);
	index = 0;
	start = 0;
	while (string[start])
	{
		while (string[start] && string[start] == ch)
			++start;
		end = start;
		while (string[end] && string[end] != ch)
			++end;
		if (string[start] && string[start] != ch)
			result[index++] = string_slice(string, start, end);
		start = end;
	}
	return (result);
}
