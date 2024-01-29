/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_compare.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 13:48:11 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/10 13:48:13 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/plib.h"

int	string_compare(char *str1, char *str2)
{
	unsigned char	*p1;
	unsigned char	*p2;

	if (!str1 || !str2)
		return (0);
	p1 = (unsigned char *)str1;
	p2 = (unsigned char *)str2;
	while (*p1 && *p1 == *p2)
	{
		++p1;
		++p2;
	}
	return (*p1 - *p2);
}
