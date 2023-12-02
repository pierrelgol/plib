/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_shuffle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 12:47:17 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/01 12:47:18 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

char	*string_shuffle(char *str)
{
	unsigned int	length;
	unsigned int	index;

	if (!str)
		return (0);
	length = string_length(str);
	index = 0;
	str = string_reverse(str);
	while (length--)
	{
		if (length & 1)
			str[index] = (char)char_to_random(str[length]);
		else
			str[index] = (char)char_to_reversecase(str[length]);
		++index;
	}
	return (0);
}
