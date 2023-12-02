/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_split_create.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 12:51:15 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/01 12:51:18 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

char	**string_split_create(unsigned int size)
{
	char	**split;

	if (size == 0)
		return (0);
	split = memory_alloc(size, sizeof(char *));
	if (!split)
		return (0);
	return (split);
}
