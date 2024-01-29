/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_set.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 21:04:38 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/10 21:04:41 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/plib.h"

char	*string_set(char *str, int ch, unsigned int n)
{
	char	*pstr;

	if (!str)
		return (0);
	pstr = str;
	while (n--)
		*pstr++ = ch;
	return (str);
}
