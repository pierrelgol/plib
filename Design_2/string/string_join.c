/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_join.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 12:46:23 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/01 12:46:24 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

char	*string_join(char *str1, char *str2)
{
	char			*result;
	unsigned int	s1length;
	unsigned int	s2length;

	if (!str1 || !str2)
		return (0);
	s1length = string_length(str1);
	s2length = string_length(str2);
	result = string_create(s1length + s2length + 1);
	if (!result)
		return (0);
	memory_copy(result, str1, s1length);
	memory_copy(&result[s1length], str2, s2length);
	return (result);
}
