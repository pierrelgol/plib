/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_fill.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 12:44:08 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/01 12:44:09 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

char	*string_fill(char *dst, int ch)
{
	if (!dst)
		return (0);
	return (memory_set(dst, ch, string_length(dst)));
}
