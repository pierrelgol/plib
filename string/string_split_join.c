/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_split_join.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 12:52:23 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/03 18:16:22 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

char	*string_split_join(char **strs, int ch)
{
	char			*result;
	unsigned int	length;
	unsigned int	i;

	if (!strs)
		return (0);
	length = string_split_length(strs) + string_split_size(strs) * 1;
	result = string_create(length + 1);
	if (!result)
		return (0);
	i = 0;
	while (*strs)
	{
		i += string_concat(&result[i], *strs);
		if (*(strs + 1) != 0)
			i += string_concat(&result[i], (char [2]){[0] = ch});
		++strs;
	}
	return (result);
}
