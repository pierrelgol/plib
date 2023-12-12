/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_split_size.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 13:11:02 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/03 13:11:02 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

unsigned int	string_split_size(char **strs)
{
	int	size;

	if (!strs)
		return (0);
	size = 0;
	while (strs[size])
		++size;
	return (size);
}
