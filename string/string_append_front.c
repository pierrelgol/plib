/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_append_front.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 12:44:32 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/01 12:44:33 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

char *string_append_front(char *str1, char *str2)
{
	char        *result;
	unsigned int rlength;
	unsigned int i;

	if (!str1 || !str2)
		return (0);
	rlength = string_length(str1) + string_length(str2);
	result = string_create(rlength + 1);
	if (!result)
		return (0);
	i = 0;
	while (*str2)
		result[i++] = *str2++;
	while (*str1)
		result[i++] = *str1++;
	return (result);
}
