/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_slice.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 20:26:26 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/10 20:26:28 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/plib.h"

char *string_slice(struct s_allocator *allocator, char *str, size_t start, size_t end)
{
	char        *result;
	size_t slen;

	if (!str)
		return (0);
	slen = string_length(str);
	if (slen < end || slen < start)
		return (0);
	result = string_create(allocator, ((slen - start) + (slen - end)) + 1);
	if (start < end)
		memory_copy(result, str + start, end - start);
	else if (start > end)
		memory_copy(result, str + end, start - end);
	return result;
}
