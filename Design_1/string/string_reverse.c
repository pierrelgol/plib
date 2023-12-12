/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_reverse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 20:24:51 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/10 20:24:59 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

char	*string_reverse(char *str)
{
	unsigned int	length;
	unsigned int	i;
	unsigned int	temp;

	if (!str)
		return (0);
	length = string_length(str);
	i = 0;
	while (i < (length - i - 1))
	{
		temp = str[i];
		str[i] = str[length - i - 1];
		str[length - i - 1] = temp;
		++i;
	}
	return (str);
}
