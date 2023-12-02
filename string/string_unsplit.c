/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_unsplit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 12:52:23 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/01 12:52:24 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

static unsigned int	string_total_length(char **strs)
{
	unsigned int	total;
	unsigned int	i;

	i = 0;
	total = 0;
	while (strs[i])
		total += (unsigned int)string_length(strs[i]);
	return (total);
}

char	*string_unsplit(char **strs)
{
	char			*result;
	unsigned int	length;
	unsigned int	i;

	if (!strs)
		return (0);
	length = string_total_length(strs);
	result = string_create(length + 1);
	if (!result)
		return (0);
	i = 0;
	while (strs[i])
		string_concat(result, strs[i++]);
	string_split_destroy(strs, i);
	return (result);
}
