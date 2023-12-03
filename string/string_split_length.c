/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_split_length.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 13:06:51 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/03 13:06:51 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

unsigned int	string_split_length(char **strs)
{
	unsigned int	length;
	unsigned int	index;

	if (!strs)
		return (0);
	index = 0;
	length = 0;
	while (strs[index])
		length += string_length(strs[index++]);
	return (length);
}
