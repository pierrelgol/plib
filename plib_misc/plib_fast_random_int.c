/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plib_fast_random_int.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 17:53:33 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/11/23 17:53:33 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

unsigned int	plib_fast_random_int(unsigned int index)
{
	index = (index << 13) ^ index;
	return ((index * (index * index * 15731 + 789221) + 1376312589) & 0x7fffffff);
}
