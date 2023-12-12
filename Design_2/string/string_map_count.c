/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_map_count.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 12:49:27 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/01 12:49:28 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

int	string_map_count(char *str, int (*f)(int ch))
{
	unsigned int	count;

	if (!str || !f)
		return (0);
	count = 0;
	while (*str)
	{
		if (f(*str))
			++count;
		++str;
	}
	return ((int)count);
}
