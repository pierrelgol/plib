/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plib_bit_bitmask_create.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 22:19:39 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/11/29 22:19:39 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

unsigned int plib_bit_bitmask_create(unsigned int start, unsigned int end)
{
	unsigned int mask;

	if (start > end || start > 31 || end > 31)
		return (0);
	mask = ((1u << (end - start + 1)) - 1) << start;
	return (mask);
}
