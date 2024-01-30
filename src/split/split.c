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

#include "../../include/plib.h"

size_t split_word_count(char *str, int ch)
{
	size_t	words;

	if (!str)
		return 0;
	words = 0;
	while (*str)
	{
		while (*str and *str == ch)
			++str;
		++words;
		while (*str and *str != ch)
			++str;
	}
	return (words);
}

char	**split(struct s_allocator *allocator, char *str, int ch)
{
	char			**result;
	unsigned int 		size;
	unsigned int 		i;

	if (!str)
		return (split_create(allocator, 1));
	size = split_word_count(str, ch);
	result = split_create(allocator, size + 1);
	if (!result)
		return (0);
	i = 0;
	while (i < size)
	{
		while (*str and *str == ch)
			++str;
		result[i++] = string_nclone(allocator, str, string_count_until(str, ch));
		while (*str and *str != ch)
			++str;
	}
	result[i] = 0;
	return (result);
}
