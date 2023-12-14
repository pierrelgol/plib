/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itable_body_resize.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 16:07:10 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/14 16:07:11 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

void	itable_body_resize(t_itable *table, unsigned int new_capacity)
{
	unsigned int	capacity_old;
	t_ientry		*entry_old;
	unsigned int	i;

	entry_old = table->body;
	capacity_old = table->capacity;
	table->body = itable_body_create(new_capacity);
	table->capacity = new_capacity;
	i = 0;
	while (i < capacity_old)
	{
		if (entry_old[i].key != NULL)
			itable_entry_set(table, entry_old[i].key, entry_old[i].value);
		++i;
	}
}
