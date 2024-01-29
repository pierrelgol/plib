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

#include "../../include/plib.h"

char	**split_create(struct s_allocator *allocator, unsigned int size)
{
	char			**split;

	split = allocator->create(allocator, size * sizeof(char *) + 1);
	if (!split)
		return (0);
	return (split);
}
