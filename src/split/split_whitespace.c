/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_whitespace.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 09:13:06 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/11 09:13:07 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/plib.h"

static unsigned int	is_whitespace(int ch)
{
	return (ch == ' ' || ch == '\t' || ch == '\v' || ch == '\r');
}

static unsigned int	split_find_size(char *string)
{
	unsigned int	size;

	if (!string)
		return (0);
	size = 0;
	while (*string)
	{
		while (*string && is_whitespace(*string))
			++string;
		++size;
		while (*string && !is_whitespace(*string))
			++string;
	}
	return (size);
}

char	**split_whitespace(struct s_allocator *allocator, char *string)
{
	char			**result;
	unsigned int	index;
	unsigned int	start;
	unsigned int	end;

	if (!string)
		return (0);
	result = split_create(allocator, split_find_size(string) + 1);
	if (!result)
		return (0);
	index = 0;
	start = 0;
	while (string[start])
	{
		while (string[start] && is_whitespace(string[start]))
			++start;
		end = start;
		while (string[end] && !is_whitespace(string[end]))
			++end;
		if (string[start] && !is_whitespace(string[start]))
			result[index++] = string_nclone(allocator, &string[start], end);
		start = end;
	}
	return (result);
}
