/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plib_char_boolset_create.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 11:57:09 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/11/23 12:22:48 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

char	*plib_char_boolset_create(char *str)
{
	char	*set;

	set = plib_memory_alloc(255, sizeof(char));
	if (!set)
		return (NULL);
	while (*str)
		set[(int)*str++] = 1;
	return (set);
}
