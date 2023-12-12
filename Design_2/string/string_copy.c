/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_copy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 12:44:01 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/01 12:44:02 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

char	*string_copy(char *dest, char *src)
{
	if (!dest || !src)
		return (0);
	memory_copy(dest, src, string_length(src));
	return (dest);
}
