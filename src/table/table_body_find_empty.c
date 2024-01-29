/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_body_find_empty.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 09:27:15 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/05 10:46:55 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/plib.h"

unsigned int	table_body_find_empty(t_table *table, char *key)
{
	int	index;

	index = table_hash(key) % table->capacity;
	while (table->body[index].key != NULL
		&& string_compare(table->body[index].key, key) != 0)
		index = (index + 1) % table->capacity;
	return (index);
}
