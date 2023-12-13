/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bit_compare_bits.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 21:16:47 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/05 10:34:01 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	bit_compare_bits(unsigned int num1, unsigned int num2, unsigned int bitPos1,
		unsigned int bitPos2)
{
	unsigned int	mask1;
	unsigned int	mask2;
	unsigned int	bit1;
	unsigned int	bit2;

	mask1 = 1 << bitPos1;
	mask2 = 1 << bitPos2;
	bit1 = (num1 & mask1) >> bitPos1;
	bit2 = (num2 & mask2) >> bitPos2;
	if (bit1 == bit2)
		return (0);
	else if (bit1 < bit2)
		return (-1);
	else
		return (1);
}
