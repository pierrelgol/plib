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
	unsigned int	slen;
	unsigned int	i;
	unsigned int	temp;

	if (!str)
		return (0);
	slen = string_length(str);
	i = 0;
	while (i < (slen - i - 1))
	{
		temp = str[i];
		str[i] = str[slen - i - 1];
		str[slen - i - 1] = temp;
		++i;
	}
	return (str);
}
