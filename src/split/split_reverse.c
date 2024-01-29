/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_reverse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 09:09:33 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/11 09:09:34 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/plib.h"

char	**split_reverse(char **split)
{
	unsigned int	size;
	unsigned int	i;
	char			*temp;

	if (!split)
		return (0);
	i = 0;
	size = split_size(split);
	while (i < (size - i - 1))
	{
		temp = split[i];
		split[i] = split[size - i - 1];
		split[size - i - 1] = temp;
		++i;
	}
	return (split);
}
