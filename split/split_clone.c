/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_clone.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 09:01:07 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/11 09:01:07 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

char	**split_clone(struct s_allocator *allocator, char **split)
{
	char			**result;
	unsigned int	i;

	if (!split)
		return (0);
	result = split_create(allocator, split_size(split) + 1);
	if (!result)
		return (0);
	i = 0;
	while (split[i])
	{
		result[i] = string_clone(allocator, split[i]);
		++i;
	}
	return (split);
}
