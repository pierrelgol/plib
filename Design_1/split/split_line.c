/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 10:20:17 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/11 10:20:18 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

static unsigned int	is_line(int ch)
{
	return (ch == '\n');
}

static unsigned int	split_find_size(char *string)
{
	unsigned int	size;

	if (!string)
		return (0);
	size = 0;
	while (*string)
	{
		while (*string && is_line(*string))
			++string;
		if (*string && !is_line(*string))
			++size;
		while (*string && !is_line(*string))
			++string;
	}
	return (size);
}

char	**split_line(char *string)
{
	char			**result;
	unsigned int	index;
	unsigned int	start;
	unsigned int	end;

	if (!string)
		return (0);
	result = split_create(split_find_size(string) + 1);
	if (!result)
		return (0);
	index = 0;
	start = 0;
	while (string[start])
	{
		while (string[start] && is_line(string[start]))
			++start;
		end = start;
		while (string[end] && !is_line(string[end]))
			++end;
		if (string[start] && !is_line(string[start]))
			result[index++] = string_slice(string, start, end);
		start = end;
	}
	return (result);
}
