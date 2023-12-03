/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_split_compare.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 18:06:48 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/03 18:06:50 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

int	string_split_compare(char **strs1, char **strs2)
{
	if (!strs1 || !strs2)
		return (0);

	while (*strs1 && string_compare(*strs1, *strs2) == 0)
	{
		++strs1;
		++strs2;
	}
	return (string_compare(*strs1, *strs2));
}
