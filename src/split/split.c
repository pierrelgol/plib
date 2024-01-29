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


char	**split(struct s_allocator *allocator, char *str, int ch)
{
	char			**result;
	unsigned int 		size;
	unsigned int 		i;

	if (!str)
		return (split_create(allocator, 1));
	size = string_count(str, ch);
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
	return (result);
}
