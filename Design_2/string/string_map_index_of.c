/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_map_index_of.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 12:49:40 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/01 12:49:41 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

int	string_map_index_of(char *str, int (*f)(int ch))
{
	int	index;

	if (!str || !f)
		return (-1);
	index = 0;
	while (str[index])
	{
		if (f(str[index]))
			return (index);
		++index;
	}
	return (-1);
}
