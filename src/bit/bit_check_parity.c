/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bit_check_parity.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 21:37:30 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/05 10:33:56 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/plib.h"

unsigned int	bit_check_parity(unsigned int num)
{
	unsigned int	parity;

	parity = 0;
	while (num)
	{
		parity ^= 1;
		num &= (num - 1);
	}
	return (parity);
}
