/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plib_string_index_of.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 13:04:27 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/11/23 13:04:31 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

int	plib_string_index_of(char *str, int ch)
{
	int	index;

	index = 0;
	while (*str)
	{
		if (*str == ch)
			return (index);
		++str;
	}
	return (-1);
}
