/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_compare.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 09:03:24 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/11 09:03:25 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/plib.h"

int	split_compare(char **split1, char **split2, unsigned int n)
{
	unsigned int	result;
	unsigned int	i;
	char			*p1;
	char			*p2;

	i = 0;
	while (split1[i] && split2[i] && n--)
	{
		p1 = split1[i];
		p2 = split2[i];
		result = string_compare(p1, p2);
		if (result != 0)
			return (result);
		++i;
	}
	return (0);
}
