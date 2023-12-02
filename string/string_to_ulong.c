/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_to_ulong.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 12:50:19 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/01 12:50:20 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

unsigned long	string_to_ulong(char *str)
{
	unsigned long long	result;

	result = 0;
	while (*str && (*str == ' ' || (*str >= 9 && *str <= 13)))
		++str;
	while (*str && (*str == '-' || *str == '+'))
		++str;
	while (*str && (*str >= '0' && *str <= '9'))
		result = ((unsigned long long)*str++ - '0') + result * 10;
	return ((unsigned long)result);
}
