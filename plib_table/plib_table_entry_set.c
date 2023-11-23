/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plib_table_entry_set.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 09:26:01 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/11/23 09:26:02 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

void	plib_table_entry_set(t_table *self, char *key, void *value)
{
	int	index;

	index = plib_table_body_find_empty(self, key);
	if (self->body[index].key != NULL)
		self->body[index].value = value;
	else
	{
		self->size++;
		if ((float)self->size / self->capacity > 0.8)
		{
			plib_table_body_resize(self, self->capacity * 2);
			index = plib_table_body_find_empty(self, key);
		}
		self->body[index].key = key;
		self->body[index].value = value;
	}
}
