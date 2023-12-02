/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_clone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 13:06:26 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/01 13:06:28 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

char	*string_clone(char *str)
{
	char			*result;
	unsigned int	length;

	if (!str)
		return (0);
	length = string_length(str);
	result = string_create(length + 1);
	if (!result)
		return (0);
	return (memory_copy(result, str, length));
}
