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

char	*string_pad(char *str, int ch, int left, int right)
{
	char			*result;
	unsigned int	rlen;
	unsigned int	slen;

	if (!str)
		return (0);
	if (left == 0 && right == 0)
		return (str);
	slen = string_length(str);
	rlen = slen + (left + right);
	result = string_create(rlen + 1);
	if (!result)
		return (0);
	string_set(result, ch, left);
	string_copy(&result[left], str, slen);
	string_set(&result[left + slen], ch, right);
	return (result);
}
