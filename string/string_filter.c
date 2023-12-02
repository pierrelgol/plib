/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_filter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 12:48:29 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/01 12:48:30 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

char	*string_filter(char *str, int ch)
{
	char			*result;
	unsigned int	rlength;
	unsigned int	i;

	if (!str)
		return (0);
	rlength = string_length(str) - (unsigned int)string_count(str, ch);
	result = string_create(rlength + 1);
	if (!result)
		return (0);
	i = 0;
	while (*str)
	{
		if (*str != ch)
			result[i++] = *str;
		++str;
	}
	return (result);
}
