/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plib_table_hash.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 09:26:24 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/11/23 09:26:26 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

unsigned long	plib_table_hash(char *str)
{
	unsigned long	seed;
	int				val;

	seed = 5381;
	while (*str)
	{
		val = *str++;
		seed = ((seed << 5) + seed) + val;
	}
	return (seed);
}
