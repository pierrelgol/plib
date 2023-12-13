/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_map_slice.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 12:49:17 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/01 12:49:17 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

char	*string_map_slice(char *str, int (*f)(int ch))
{
	char			*slice;
	unsigned int	start;
	unsigned int	end;

	if (!str || !f)
		return (0);
	start = 0;
	while (str[start] && !f(str[start]))
		++start;
	end = start;
	while (str[end] && f(str[end]))
		++end;
	slice = string_slice(str, start, end);
	if (!slice)
		return (0);
	return (slice);
}
