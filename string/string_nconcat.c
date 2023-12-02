/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_nconcat.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 12:43:43 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/01 12:43:43 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

int	string_nconcat(char *dest, char *src, unsigned int n)
{
	unsigned int	dlength;
	unsigned int	slength;

	if (!dest || !src || !n)
		return (0);
	dlength = string_length(dest);
	slength = string_length(src);
	if (dlength + slength > n)
		slength = n - dlength;
	memory_copy(&dest[dlength], src, slength);
	return ((int)slength);
}
