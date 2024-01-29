/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_nclone.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:45:11 by pollivie          #+#    #+#             */
/*   Updated: 2024/01/29 14:45:12 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/plib.h"

char	*string_nclone(struct s_allocator *allocator, char *str, size_t n)
{
	char			*result;

	if (n == 0)
		return (allocator->create(allocator, 1));
	result = allocator->create(allocator, n + 1);
	string_copy(result, str, n);
	return (result);
}

