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

static unsigned int	split_find_count(char *str, unsigned int n)
{
	unsigned int	count;
	unsigned int	slen;

	if (!str)
		return (0);
	if (n == 0)
		return (1);
	slen = string_length(str);
	count = 0;
	while ((count * n) < slen)
		++count;
	return (count);
}

char	**split_nsplit(struct s_allocator *allocator, char *str, unsigned int n)
{
	char			**result;
	unsigned int	slen;
	unsigned int	i;
	unsigned int	j;

	if (!str)
		return (0);
	slen = string_length(str);
	result = split_create(allocator, split_find_count(str, n) + 1);
	if (!result)
		return (0);
	i = 0;
	j = 0;
	while (str[j])
	{
		if ((j + n) <= slen)
			result[i++] = string_slice(allocator, &str[j], 0, n);
		else
		{
			result[i++] = string_clone(allocator, &str[j]);
			n = string_length(result[i - 1]);
		}
		j += n;
	}
	return (result);
}
