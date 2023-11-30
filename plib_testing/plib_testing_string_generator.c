/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plib_testing_string_generator.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 17:34:55 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/11/23 17:42:51 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

char	*plib_testing_string_generator(char *set, int length)
{
	char	*result;
	int	i;
	int	ch;

	result = plib_memory_alloc(length + 1, sizeof(char));
	i = 0;
	while (i < length)
	{
		ch = rand() % 255;
		while (set[ch] == 0)
			ch = rand() % 255;
		result[i++] = ch;
	}
	return (result);
}

