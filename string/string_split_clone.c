/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_split_clone.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 17:46:19 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/03 17:46:20 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../plib.h"

char	**string_split_clone(char **strs)
{
	unsigned int size;
	unsigned int index;
	char **result;

	if (!strs)
		return (0);
	size = string_split_size(strs);
	result = string_split_create(size + 1);
	if (!result)
		return (0);
	index = 0;
	while(index < size)
	{
		result[index] = string_clone(strs[index]);
		++index;
	}
	return (result);
}
