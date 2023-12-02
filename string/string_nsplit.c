/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_nsplit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 12:51:51 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/01 12:51:52 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

char	**string_nsplit(char *str, unsigned int n)
{
	char			**result;
	unsigned int	index;
	unsigned int	length;
	unsigned int	end;

	index = 0;
	length = (string_length(str)) / n;
	result = string_split_create(n + 1);
	if (!result)
		return (0);
	while (index < n)
	{
		end = string_length(&str[length * index]);
		if (end > length)
			end = length;
		result[index] = string_slice(str, length * index, end);
		if (!result[index])
			return (string_split_destroy(result, index));
		++index;
	}
	return (result);
}
