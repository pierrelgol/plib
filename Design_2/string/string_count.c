/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_count.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 13:04:40 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/01 13:04:50 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

int	string_count(char *str, int ch)
{
	unsigned int	count;

	if (!str)
		return (0);
	count = 0;
	while (*str)
	{
		if (*str++ == ch)
			++count;
	}
	return ((int)count);
}
