/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_pad.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 21:04:47 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/10 21:04:49 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

char	*string_pad(struct s_allocator *allocator, char *str, int ch, size_t n)
{
	char			*result;
	unsigned int	rlen;
	unsigned int	slen;

	if (!str)
		return (0);
	if (n == 0)
		return (str);
	slen = string_length(str);
	rlen = slen + (n * 2);
	result = string_create(allocator, rlen + 1);
	if (!result)
		return (0);
	string_set(result, ch, n);
	string_copy(&result[n], str, slen);
	string_set(&result[n + slen], ch, n);
	return (result);
}
