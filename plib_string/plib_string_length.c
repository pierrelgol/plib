/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plib_string_length.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 09:37:33 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/11/23 09:37:34 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

int	plib_string_length(char *str)
{
	char	*ptr_str;

	if (!str)
		return (0);
	ptr_str = str;
	while (*ptr_str && *(ptr_str + 1) && *(ptr_str + 2) && *(ptr_str + 3))
		ptr_str += 4;
	while (*ptr_str)
		++ptr_str;
	return (ptr_str - str);
}
