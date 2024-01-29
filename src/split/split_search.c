/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_search.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 10:08:01 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/11 10:08:02 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/plib.h"

char	*split_binary_search(char **split, int size, char *str)
{
	int	low;
	int	high;
	int	mid;
	int	res;

	low = 0;
	high = size - 1;
	while (low <= high)
	{
		mid = low + (high - low) / 2;
		res = string_compare(str, split[mid]);
		if (res == 0)
			return (split[mid]);
		else if (res < 0)
			high = mid - 1;
		else
			low = mid + 1;
	}
	return (0);
}

static char	*split_linear_search(char **split, char *str)
{
	int	i;

	i = 0;
	while (split[i])
	{
		if (string_compare(str, split[i]) == 0)
			return (split[i]);
		++i;
	}
	return (0);
}

char	*split_search(char **split, char *str, int sorted)
{
	char	*result;

	if (!split || !str)
		return (0);
	result = 0;
	if (!sorted)
		result = split_linear_search(split, str);
	else
		result = split_binary_search(split, split_size(split), str);
	return (result);
}
