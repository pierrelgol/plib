/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plib_char_set_destroy.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 12:24:46 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/11/23 12:24:47 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

char	*plib_char_set_destroy(char *set)
{
	return (plib_memory_dealloc(set));
}
