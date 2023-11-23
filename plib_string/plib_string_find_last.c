/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plib_string_find_last.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 09:35:08 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/11/23 10:28:10 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

char	*plib_string_find_last(char *str, int ch)
{
	char	*ptr_str;
	char	*ptr_last;

	ptr_str = str;
	ptr_last = NULL;
	while (*ptr_str)
	{
		if (*ptr_str == ch)
			ptr_last = ptr_str;
		++ptr_str;
	}
	return (ptr_last);
}
