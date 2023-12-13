/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 09:25:40 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/05 10:47:21 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

t_table	*table_create(void)
{
	t_table	*table;

	table = memory_create(sizeof(t_table), 1);
	if (!table)
		return (NULL);
	table->size = 0;
	table->capacity = DEFAULT_TABLE_SIZE;
	table->body = table_body_create(table->capacity);
	return (table);
}
