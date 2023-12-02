/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_reverse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 12:46:36 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/01 12:46:37 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

char	*string_reverse(char *str)
{
	unsigned int	length;
	unsigned int	i;

	if (!str)
		return (0);
	length = string_length(str);
	i = 0;
	while (i < (length - i - 1))
	{
		str[i] = str[length - i - 1];
		++i;
	}
	return (str);
}
