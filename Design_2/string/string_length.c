/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_length.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 12:16:26 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/01 12:16:27 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

unsigned int	string_length(char *str)
{
	char	*pstr;

	if (!str)
		return (0);
	pstr = str;
	while (*pstr && *(pstr + 1) && *(pstr + 2) && *(pstr + 3))
		pstr += 4;
	while (*pstr)
		++pstr;
	return ((unsigned int)(pstr - str));
}
