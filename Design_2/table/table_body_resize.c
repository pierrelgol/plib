/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_body_resize.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 09:27:00 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/05 10:47:15 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

void	table_body_resize(t_table *self, unsigned int capacity)
{
	unsigned int	old_capacity;
	t_entry			*old;
	unsigned int	i;

	old = self->body;
	old_capacity = self->capacity;
	self->body = table_body_create(capacity);
	self->capacity = capacity;
	i = 0;
	while (i < old_capacity)
	{
		if (old[i].key != NULL)
			table_entry_set(self, old[i].key, old[i].value);
		++i;
	}
}
