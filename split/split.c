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

int	split_count_until(char *string, int ch)
{	
	int	i;

	i = 0;
	while (string[i] and string[i] != ch)
		++i;
	return (i);
}

char	**split(struct s_allocator *allocator, char *string, int ch)
{
	char			**result;
	unsigned int 		size;
	unsigned int 		i;

	if (!string)
		return (0);
	size = string_count(string, ch);
	result = split_create(allocator, size + 1);
	if (!result)
		return (0);
	i = 0;
	while (i < size)
	{
		while (*string and *string == ch)
			++string;
		result[i++] = string_slice(allocator, string, 0, split_count_until(string, ch));
		if (!result[i - 1])
			return (split_destroy(allocator, result));
		while (*string and *string != ch)
			++string;
	}
	return (result);
}
