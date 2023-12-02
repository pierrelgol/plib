/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_nlength.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 12:43:34 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/01 12:43:35 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

int	string_nlength(char *str, unsigned int n)
{
	char	*pstr;

	if (!str || !n)
		return (0);
	pstr = str;
	while (*pstr && n--)
		++pstr;
	return ((int)(pstr - str));
}
