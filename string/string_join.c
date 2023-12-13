/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_join.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 13:50:23 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/10 13:50:25 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

char	*string_join(char *str1, char *str2)
{
	char			*result;
	unsigned int	s1len;
	unsigned int	s2len;

	if (!str1 || !str2)
		return (0);
	s1len = string_length(str1);
	s2len = string_length(str2);
	result = string_create(s1len + s2len + 1);
	if (!result)
		return (0);
	string_concat(result, str1, s1len);
	string_concat(result, str2, s2len);
	return (result);
}
