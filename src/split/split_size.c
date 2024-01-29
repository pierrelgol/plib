/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_size.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 08:59:22 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/11 08:59:38 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/plib.h"

unsigned int	split_size(char **split)
{
	unsigned int	size;

	if (!split)
		return (0);
	size = 0;
	while (split[size])
		++size;
	return (size);
}
