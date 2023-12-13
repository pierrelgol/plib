/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_njoin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 12:46:30 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/01 12:46:30 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

char	*string_njoin(char *str1, char *str2, unsigned int n)
{
	char			*result;
	unsigned int	s1length;
	unsigned int	s2length;

	if (!str1 || !str2)
		return (0);
	s1length = string_length(str1) - n;
	s2length = string_length(str2) - n;
	if (s1length <= 0 || s2length <= 0)
		return (0);
	result = string_create(s1length + s2length + 1);
	if (!result)
		return (0);
	memory_copy(result, str1, s1length);
	memory_copy(&result[s1length], str2, s2length);
	return (result);
}
