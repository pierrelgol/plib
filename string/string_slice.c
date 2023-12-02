/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_slice.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 12:47:24 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/01 12:47:24 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

static unsigned int	abs_length(unsigned int n)
{
	return (((n < 0) * (-(n))) + ((n >= 0) * n));
}

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
	result = string_create((abs_length(end - start)) + 1);
	index = 0;
	if (start <= end)
	{
		while (start < end)
			result[index++] = str[start++];
	}
	else
	{
		while (start >= end)
			result[index++] = str[start--];
	}
	return (result);
}
