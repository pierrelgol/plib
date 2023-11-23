/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plib_string_substring_create.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 09:39:25 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/11/23 09:39:26 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

char	*plib_string_substring_create(char *str, int start, int length)
{
	char	*result;
	int		slen;

	slen = plib_string_length(str);
	if (start > slen)
		return (plib_string_duplicate(""));
	if (length > (slen - start))
		length = slen - start;
	result = calloc((length + 1), sizeof(char));
	if (!result)
		return (NULL);
	plib_string_copy(result, &str[start], length);
	return (result);
}
