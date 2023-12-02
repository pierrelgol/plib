/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_index_of.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 12:16:50 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/01 12:16:51 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

int	string_index_of(char *str, int ch)
{
	unsigned int	index;

	if (!str)
		return (-1);
	index = 0;
	while (str[index])
	{
		if (str[index] == ch)
			return ((int)index);
		++index;
	}
	return (-1);
}
