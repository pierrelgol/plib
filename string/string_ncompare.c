/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_ncompare.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 12:32:43 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/11 12:32:43 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

int	string_ncompare(char *str1, char *str2, unsigned int n)
{
	unsigned char	*p1;
	unsigned char	*p2;

	if (!str1 || !str2)
		return (0);
	p1 = (unsigned char *)str1;
	p2 = (unsigned char *)str2;
	while (*p1 && *p1 == *p2 && n--)
	{
		++p1;
		++p2;
	}
	return (*p1 - *p2);
}
