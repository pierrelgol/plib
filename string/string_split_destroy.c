/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_split_destroy.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 12:51:28 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/01 12:51:29 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

char	**string_split_destroy(char **str, unsigned int index)
{
	unsigned int	i;

	if (!str)
		return (0);
	i = 0;
	while (i < index)
		memory_dealloc(str[i++]);
	return (memory_dealloc(str));
}
