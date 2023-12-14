/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itable_hash.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 16:07:03 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/14 16:07:04 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

unsigned long	itable_hash(char *str)
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
