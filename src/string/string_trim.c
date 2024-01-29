/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_trim.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 21:19:57 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/10 21:19:59 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/plib.h"

char	*string_trim(struct s_allocator *allocator, char *str, int ch)
{
	char			*result;
	unsigned int	start;
	unsigned int	end;

	if (!str)
		return (0);
	start = string_count_leading(str, ch);
	end = string_length(str) + string_count_trailing(str, ch);
	result = string_create(allocator, (end - start) + 1);
	if (!result)
		return (0);
	string_copy(result, &str[start], (end - start));
	return (result);
}
