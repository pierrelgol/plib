/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 08:51:51 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/11 08:51:52 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

char	**split_create(unsigned int size)
{
	unsigned int	i;
	char			**split;

	split = malloc(size * sizeof(char *));
	if (!split)
		return (0);
	i = 0;
	while (i < size)
		split[i++] = 0;
	return (split);
}
