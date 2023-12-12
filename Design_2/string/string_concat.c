/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_concat.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 12:20:32 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/01 12:20:33 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

int	string_concat(char *dest, char *src)
{
	unsigned int	slength;

	if (!dest || !src)
		return (0);
	slength = string_length(src);
	memory_copy(&dest[string_length(dest)], src, slength);
	return ((int)slength);
}
