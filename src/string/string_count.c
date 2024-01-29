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

#include "../../include/plib.h"

unsigned int	string_count(char *str, int ch)
{
	unsigned int	count;

	if (!str)
		return (0);
	count = 0;
	while (*str)
	{
		if (*str == ch)
			++count;
		++str;
	}
	return (count);
}
