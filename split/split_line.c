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

static unsigned int	split_find_size(char *str)
{
	unsigned int	size;

	if (!str)
		return (0);
	size = 0;
	while (*str)
	{
		while (*str && is_line(*str))
			++str;
		if (*str && !is_line(*str))
			++size;
		while (*str && !is_line(*str))
			++str;
	}
	return (size);
}

char	**split_line(struct s_allocator *allocator, char *str)
{
	char			**result;
	unsigned int	index;
	unsigned int	start;
	unsigned int	end;

	if (!str)
		return (0);
	result = split_create(allocator, split_find_size(str) + 1);
	if (!result)
		return (0);
	index = 0;
	start = 0;
	while (str[start])
	{
		while (str[start] && is_line(str[start]))
			++start;
		end = start;
		while (str[end] && !is_line(str[end]))
			++end;
		if (str[start] && !is_line(str[start]))
			result[index++] = string_slice(allocator, str, start, end);
		start = end;
	}
	return (result);
}
