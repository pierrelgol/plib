/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plib_string_trim.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 09:40:19 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/11/23 09:40:21 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

char	*plib_string_trim(char *str, char *charset)
{
	unsigned int	start;
	unsigned int	end;
	char			*result;
	char			*set;

	start = 0;
	end = plib_string_length(str);
	set = plib_char_boolset_create_from((char[255]){0}, charset);
	while (str[start] && set[(int)str[start]] == 1)
		++start;
	while (start < end && set[(int)str[end - 1]] == 1)
		--end;
	result = plib_memory_alloc(sizeof(char), (end - start + 1));
	if (!result)
		return (NULL);
	plib_string_copy(result, &str[start], (end - start) + 1);
	return (result);
}
