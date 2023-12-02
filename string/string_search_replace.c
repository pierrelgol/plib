/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_search_replace.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 12:48:02 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/01 12:48:02 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

char	*string_search_replace(char *str, char *sub, char *with)
{
	char	*ptr;

	if (!str || !sub || !with)
		return (0);
	ptr = string_search(str, sub);
	if (!ptr)
		return (0);
	while (*ptr && *sub && *with)
	{
		*ptr++ = *with++;
		sub++;
	}
	return (str);
}
