/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plib_string_compare_until.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 09:30:44 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/11/24 09:30:45 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

int	plib_string_compare_until(char *str1, char *str2, unsigned int cmpsize)
{
	char	*ptr_s1;
	char	*ptr_s2;

	ptr_s1 = str1;
	ptr_s2 = str2;
	if (cmpsize == 0)
		return (0);
	while (--cmpsize && *ptr_s1 && *ptr_s1 == *ptr_s2)
	{
		++ptr_s1;
		++ptr_s2;
	}
	return ((unsigned char)*ptr_s1 - *ptr_s2);
}
