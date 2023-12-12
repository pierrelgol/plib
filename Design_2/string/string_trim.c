/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_trim.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 12:45:38 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/01 12:45:38 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

char	*string_trim(char *str, int ch)
{
	char			*result;
	unsigned int	start;
	unsigned int	end;

	if (!str)
		return (0);
	start = 0;
	while (str[start] == ch)
		++start;
	end = string_length(str);
	while (end >= 0 && str[end - 1] == ch)
		--end;
	result = string_create((end - start) + 1);
	if (!result)
		return (0);
	memory_copy(result, &str[start], (end - start));
	return (result);
}
