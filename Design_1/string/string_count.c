/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_count_char.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 14:10:37 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/10 14:10:39 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

unsigned int	string_count(char *src, int ch)
{
	unsigned int	count;

	if (!src)
		return (0);
	count = 0;
	while (*src)
	{
		if (*src == ch)
			++count;
		++src;
	}
	return (count);
}
