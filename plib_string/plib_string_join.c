/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plib_string_join.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 09:34:32 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/11/23 09:34:33 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

char	*plib_string_join(char *str1, char *str2)
{
	char			*result;
	unsigned int	size;

	size = plib_string_length(str1) + plib_string_length(str2) + 1;
	result = (char *)calloc(sizeof(char), size);
	if (!result)
		return (NULL);
	plib_string_concat(result, str1, size);
	plib_string_concat(result, str2, size);
	return (result);
}
