/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plib_string_to_int.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 09:40:06 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/11/23 09:40:08 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

int	plib_string_to_int(char *nbr)
{
	long	result;
	long	sign;

	sign = 1;
	result = 0;
	while (*nbr && (*nbr == ' ' || (*nbr >= 9 && *nbr <= 13)))
		++nbr;
	if (*nbr && (*nbr == '-' || *nbr == '+'))
	{
		if (*nbr++ == '-')
			sign *= -1;
	}
	while (*nbr && (*nbr >= '0' && *nbr <= '9'))
		result = (*nbr++ - '0') + result * 10;
	return (result * sign);
}
