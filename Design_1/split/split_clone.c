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

char	**split_clone(char **split)
{
	char			**result;
	unsigned int	i;

	if (!split)
		return (0);
	result = split_create(split_size(split) + 1);
	if (!result)
		return (0);
	i = 0;
	while (split[i])
	{
		result[i] = string_clone(split[i]);
		++i;
	}
	return (split);
}
