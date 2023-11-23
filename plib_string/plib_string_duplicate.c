/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plib_string_duplicate.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 09:35:24 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/11/23 09:35:25 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

char	*plib_string_duplicate(char *str)
{
	char	*result;
	int		length;

	length = plib_string_length(str);
	result = (char *)calloc(sizeof(char), length + 1);
	if (!result)
		return (NULL);
	plib_string_copy(result, str, length);
	return (result);
}
