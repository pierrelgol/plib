/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plib_table_body_find_empty.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 09:27:15 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/11/23 09:27:16 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"
#include <string.h>

unsigned int	plib_table_body_find_empty(t_table *self, char *key)
{
	int	index;

	index = plib_table_hash(key) % self->capacity;
	while (self->body[index].key != NULL
		&& plib_string_compare(self->body[index].key, key) != 0)
		index = (index + 1) % self->capacity;
	return (index);
}
