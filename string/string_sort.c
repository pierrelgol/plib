/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 12:47:30 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/01 12:47:30 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

char	*string_sort(char *str, int (*f)(int ch1, int ch2))
{
	unsigned int	temp;
	unsigned int	i;

	if (!str || !f)
		return (0);
	i = 1;
	while (str[i])
	{
		while (i >= 1 && f(str[i - 1], str[i]) == 0)
		{
			temp = (unsigned int)str[i - 1];
			str[i - 1] = str[i];
			str[i--] = (char)temp;
		}
		++i;
	}
	return (str);
}
