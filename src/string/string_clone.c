/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_clone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 20:18:07 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/10 20:18:09 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/plib.h"

char	*string_clone(struct s_allocator *allocator, const char *str)
{
	char			*result;
	unsigned int	rlen;

	rlen = string_length(str);
	result = string_create(allocator, rlen + 1);
	string_copy(result, str, rlen);
	return (result);
}
