/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plib_char_boolset_create_from.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 13:16:48 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/11/23 13:16:49 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

char	*plib_char_boolset_create_from(char *empty_set, char *str)
{
	while (*str)
		empty_set[(int)*str++] = 1;
	return (empty_set);
}
