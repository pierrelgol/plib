/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_unsplit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 14:18:29 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/11 14:18:30 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/plib.h"

char	*split_unsplit(struct s_allocator *allocator, char **split, int sep)
{
	char			*result;
	unsigned int	rlen;
	unsigned int	size;
	unsigned int	i;

	if (!split)
		return (0);
	size = split_size(split);
	rlen = split_length(split) + size;
	result = string_create(allocator, rlen + 1);
	if (!rlen)
		return (0);
	i = 0;
	while (i < size)
	{
		string_concat(result, split[i], string_length(split[i]));
		if ((i + 1) < size)
			string_concat(result, (char [2]){[0] = sep}, 1);
		++i;
	}
	return (result);
}
