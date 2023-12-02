/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_starts_with.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 12:23:49 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/01 12:24:17 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

int	string_starts_with(char *str, char *prefix)
{
	unsigned int	length;

	if (!str || !prefix)
		return (0);
	length = string_length(prefix);
	return ((int *)string_nsearch(str, prefix, length) != 0);
}
