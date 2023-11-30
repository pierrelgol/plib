/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plib_bit_swap_bits.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 21:17:03 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/11/29 21:17:04 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

unsigned int	plib_bit_swap_bits(unsigned int num, unsigned int pos1,
		unsigned int pos2, unsigned int nbits)
{
	unsigned int	swp;
	unsigned int	mask;

	mask = ((1U << nbits) - 1) << pos1 | ((1U << nbits) - 1) << pos2;
	swp = (num >> pos1) ^ (num >> pos2);
	swp &= ((1U << nbits) - 1);
	return (num ^ (((swp << pos1) | (swp << pos2)) & mask));
}
