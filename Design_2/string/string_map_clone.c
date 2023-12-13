/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_map_clone.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 12:49:10 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/01 12:49:10 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

char	*string_map_clone(char *str, int (*f)(int ch))
{
	char			*result;
	unsigned int	i;

	if (!str || !f)
		return (0);
	result = string_clone(str);
	if (!result)
		return (0);
	i = 0;
	while (result[i])
		result[i++] = (char)f(*str++);
	return (result);
}
