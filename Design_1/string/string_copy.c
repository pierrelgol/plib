/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_copy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 13:25:31 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/10 13:25:38 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

char	*string_copy(char *dest, char *src, unsigned int n)
{
	unsigned int	index;

	if (!dest || !src)
		return (0);
	index = 0;
	while (*src && index < n)
		dest[index++] = *src++;
	while (index < n)
		dest[index++] = '\0';
	return (dest);
}
