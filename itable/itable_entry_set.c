/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itable_entry_set.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 16:06:53 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/14 16:06:53 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

void	itable_entry_set(t_itable *table, char *key, long value)
{
	int	index;

	index = itable_body_find_empty(table, key);
	if (table->body[index].key != NULL)
		table->body[index].value = value;
	else
	{
		table->size++;
		if ((float)table->size / table->capacity > 0.8)
		{
			itable_body_resize(table, table->capacity * 2);
			index = itable_body_find_empty(table, key);
		}
		table->body[index].key = key;
		table->body[index].value = value;
	}
}
