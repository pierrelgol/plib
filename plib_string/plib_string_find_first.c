/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plib_string_find_first.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 09:34:55 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/11/23 10:28:00 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

char	*plib_string_find_first(char *str, int ch)
{
	char	*ptr_str;

	ptr_str = str;
	while (*ptr_str)
	{
		if (*ptr_str == ch)
			return (ptr_str);
		++ptr_str;
	}
	return (NULL);
}
