/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_slice.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 20:26:26 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/10 20:26:28 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

char	*string_slice(char *str, unsigned int start, unsigned int end)
{
	char			*result;
	unsigned int	slength;
	unsigned int	index;

	if (!str)
		return (0);
	slength = string_length(str);
	if (slength < end || slength < start)
		return (0);
	result = string_create(((slength - start) + (slength - end)) + 1);
	index = 0;
	if (start <= end)
	{
		while (start < end)
			result[index++] = str[start++];
	}
	else
	{
		while (start > end)
			result[index++] = str[--start];
	}
	return (result);
}
