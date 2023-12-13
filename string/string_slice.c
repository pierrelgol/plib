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
	unsigned int	slen;
	unsigned int	i;

	if (!str)
		return (0);
	slen = string_length(str);
	if (slen < end || slen < start)
		return (0);
	result = string_create(((slen - start) + (slen - end)) + 1);
	i = 0;
	if (start <= end)
	{
		while (start < end)
			result[i++] = str[start++];
	}
	else
	{
		while (start > end)
			result[i++] = str[--start];
	}
	return (result);
}
