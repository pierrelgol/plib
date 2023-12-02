/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_pad_left.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 12:46:08 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/01 12:46:09 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

char	*string_pad_left(char *str, int ch, unsigned int n)
{
	char			*result;
	unsigned int	rlength;
	unsigned int	slength;

	if (!str)
		return (0);
	if (n == 0)
		return (str);
	slength = string_length(str);
	rlength = slength + (n);
	result = string_create(rlength + 1);
	if (!result)
		return (0);
	memory_set(result, ch, n);
	memory_copy(&result[n - 1], str, slength);
	return (result);
}
