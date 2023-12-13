/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 20:42:25 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/10 20:42:32 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

char	*string_sort(char *str)
{
	char			temp;
	unsigned int	i;
	unsigned int	j;

	if (!str || !*str)
		return (0);
	i = 1;
	while (str[i])
	{
		j = i;
		while (j >= 1 && str[j - 1] <= str[j])
		{
			temp = str[j - 1];
			str[j - 1] = str[j];
			str[j] = temp;
			--j;
		}
		++i;
	}
	return (str);
}
