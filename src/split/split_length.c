/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_length.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 08:55:08 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/11 08:55:10 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/plib.h"

unsigned int	split_length(char **split)
{
	unsigned int	total;
	unsigned int	i;

	if (!split)
		return (0);
	total = 0;
	i = 0;
	while (split[i])
		total += string_length(split[i++]);
	return (total);
}
