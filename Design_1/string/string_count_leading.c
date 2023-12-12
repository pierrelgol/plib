/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_count_leading_char.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 14:39:49 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/10 14:39:50 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

unsigned int	string_count_leading(char *src, int ch)
{
	unsigned int	count;

	if (!src)
		return (0);
	count = 0;
	while (*src == ch)
	{
		++src;
		++count;
	}
	return (count);
}
