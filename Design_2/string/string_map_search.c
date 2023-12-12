/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_map_search.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 12:48:43 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/01 12:48:44 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

char	*string_map_search(char *str, int (*f)(int ch))
{
	unsigned int	index;

	if (!str || !f)
		return (0);
	index = 0;
	while (str[index])
	{
		if (f(str[index]))
			return (&str[index]);
		++index;
	}
	return (0);
}
