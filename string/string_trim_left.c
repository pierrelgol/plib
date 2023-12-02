/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_trim_left.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 12:45:45 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/01 12:45:46 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

char	*string_trim_left(char *str, int ch)
{
	char			*result;
	unsigned int	length;
	unsigned int	start;

	if (!str)
		return (0);
	start = 0;
	length = string_length(str);
	while (str[start] == ch)
		++start;
	result = string_create((length - start) + 1);
	if (!result)
		return (0);
	memory_copy(result, &str[start], (length - start));
	return (result);
}
