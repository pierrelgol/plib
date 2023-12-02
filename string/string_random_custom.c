/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_random_custom.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 10:04:16 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/02 10:04:16 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

char	*string_random_custom(char *set, unsigned int n)
{
	char			*result;
	unsigned int	ch;
	unsigned int	i;

	if (!set || !n)
		return (0);
	result = string_create(n + 1);
	if (!result)
		return (0);
	i = 0;
	ch = 42;
	while (i < n)
	{
		ch = (unsigned int)char_to_random((int)ch) % 255;
		while (set[ch] == 0)
			ch = (unsigned int)char_to_random((int)ch) % 255;
		result[i++] = (char)ch;
	}
	return (result);
}

