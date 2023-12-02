/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_random.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 12:47:43 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/01 12:47:45 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

char	*string_random(unsigned int n)
{
	char			*result;
	unsigned int	ch;
	unsigned int	i;

	result = string_create(n + 1);
	if (!result)
		return (0);
	i = 0;
	ch = 42;
	while (i < n)
	{
		ch = ((unsigned int)char_to_random((int)ch) + 32) % 126;
		result[i++] = (char)ch;
	}
	return (result);
}
