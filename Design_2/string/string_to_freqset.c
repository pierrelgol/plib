/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_to_freqset.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 12:50:56 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/01 12:50:57 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

char	*string_to_freqset(char *str, char set[255])
{
	if (!str || !set)
		return (0);
	while (*str)
	{
		set[(int)*str] += 1;
		++str;
	}
	return (set);
}
