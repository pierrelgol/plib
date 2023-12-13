/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_ends_with.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 12:26:17 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/01 12:26:18 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

int	string_ends_with(char *str, char *sufix)
{
	unsigned int	slen;
	unsigned int	len;

	if (!str || !sufix)
		return (0);
	slen = string_length(str);
	len = string_length(sufix);
	if (slen <= len)
		return (0);
	return (string_nsearch(&str[slen - len], sufix, len) != 0);
}
