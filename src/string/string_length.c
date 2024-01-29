/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_length.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 13:20:28 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/10 13:20:29 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/plib.h"

unsigned int	string_length(const char *src)
{
	unsigned int	length;

	if (!src)
		return (0);
	length = 0;
	while (src[length])
		++length;
	return (length);
}
