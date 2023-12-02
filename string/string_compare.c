/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_compare.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 12:21:34 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/01 12:21:59 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

int	string_compare(char *str1, char *str2)
{
	if (!str1 || !str2)
		return (0);

	while (*str1 && *((unsigned char *)str1) == *((unsigned char *)str2))
	{
		++str1;
		++str2;
	}
	return (*((unsigned char *)str1) - *((unsigned char *)str2));
}
