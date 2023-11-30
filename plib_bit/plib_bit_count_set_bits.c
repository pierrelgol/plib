/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plib_bit_count_set_bits.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 21:15:35 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/11/29 21:15:36 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

unsigned int	plib_bit_count_set_bits(unsigned int num)
{
	int	count;

	count = 0;
	while (num)
	{
		num &= (num - 1);
		++count;
	}
	return (count);
}
