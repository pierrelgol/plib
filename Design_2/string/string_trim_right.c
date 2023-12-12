/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_trim_right.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 12:45:53 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/01 12:45:53 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

char	*string_trim_right(char *str, int ch)
{
	char			*result;
	unsigned int	length;
	unsigned int	end;

	if (!str)
		return (0);
	length = string_length(str);
	if (length == 0)
		return (str);
	end = 0;
	while (str[length - end - 1] == ch)
		++end;
	result = string_create((length - end) + 1);
	if (!result)
		return (0);
	memory_copy(result, str, (length - end));
	return (result);
}
