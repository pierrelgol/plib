/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing_fstring_generator.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 21:05:29 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/06 21:05:30 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

char	*testing_fstring_generator(char *around, char *inside, int length)
{
	char	*result;
	int		i;
	int		ch;

	result = memory_alloc(length + 1, sizeof(char));
	i = 0;
	while (i < length)
	{
		if (i < (length / 3) || i > ((length / 3) * 2))
		{
			ch = rand() % 255;
			while (around[ch] == 0)
				ch = rand() % 255;
			result[i++] = ch;
		}
		else
		{
			ch = rand() % 255;
			while (inside[ch] == 0)
				ch = rand() % 255;
			result[i++] = ch;
		}
	}
	return (result);
}
