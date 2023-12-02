/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_nclone.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 12:43:25 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/01 12:43:26 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

char	*string_nclone(char *str, unsigned int n)
{
	unsigned int	length;
	char			*result;

	if (!str || n == 0)
		return (0);
	length = string_length(str);
	if (length > n)
		return (0);
	result = string_create(n + 1);
	if (!result)
		return (0);
	return (memory_copy(result, str, n));
}
