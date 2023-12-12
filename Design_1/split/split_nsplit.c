/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_nsplit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 10:23:11 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/11 10:23:12 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

static unsigned int	split_find_count(char *string, unsigned int n)
{
	unsigned int	count;
	unsigned int	slen;

	if (!string)
		return (0);
	if (n == 0)
		return (1);
	slen = string_length(string);
	count = 0;
	while ((count * n) < slen)
		++count;
	return (count);
}

char	**split_nsplit(char *string, unsigned int n)
{
	char			**result;
	unsigned int	len;
	unsigned int	i;
	unsigned int	j;

	if (!string)
		return (0);
	len = string_length(string);
	result = split_create(split_find_count(string, n) + 1);
	if (!result)
		return (0);
	i = 0;
	j = 0;
	while (string[j])
	{
		if ((j + n) <= len)
			result[i++] = string_slice(&string[j], 0, n);
		else
		{
			result[i++] = string_clone(&string[j]);
			n = string_length(result[i - 1]);
		}
		j += n;
	}
	return (result);
}
