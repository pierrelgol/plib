/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plib_bit_bitmask_combine.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 22:20:49 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/11/29 22:20:53 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

unsigned int plib_bit_bitmask_combine(unsigned int mask1, unsigned int mask2)
{
	return (mask1 | mask2);
}
