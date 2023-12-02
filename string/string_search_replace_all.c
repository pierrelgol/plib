/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_search_replace_all.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 12:48:12 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/01 12:48:13 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

char	*string_search_replace_all(char *str, char *sub, char *with)
{
	if (!str || !sub || !with)
		return (0);
	while (string_search(str, sub))
		string_search_replace(str, sub, with);
	return (str);
}
