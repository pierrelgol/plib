/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_to_uint.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 12:50:07 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/01 12:50:08 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

unsigned int	string_to_uint(char *str)
{
	unsigned long	result;

	result = 0;
	while (*str && (*str == ' ' || (*str >= 9 && *str <= 13)))
		++str;
	while (*str && (*str == '-' || *str == '+'))
		++str;
	while (*str && (*str >= '0' && *str <= '9'))
		result = ((unsigned int)*str++ - '0') + result * 10;
	return ((unsigned int)result);
}
