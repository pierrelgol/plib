/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_strip_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 12:45:03 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/01 12:45:05 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

char	*string_strip_back(char *source, char *to_remove)
{
	char			*result;
	unsigned int	slen;
	unsigned int	rmlen;

	if (!source || !to_remove)
		return (0);
	if (string_ends_with(source, to_remove))
	{
		slen = string_length(source);
		rmlen = string_length(to_remove);
		result = string_slice(source, 0, slen - rmlen);
		if (!result)
			return (0);
		return (result);
	}
	return (source);
}
