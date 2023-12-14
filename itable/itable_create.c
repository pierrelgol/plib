/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itable_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 16:05:08 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/14 16:05:09 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

t_itable	*itable_create(void)
{
	t_itable	*table;

	table = memory_create(sizeof(t_itable), 1);
	if (!table)
		return (NULL);
	table->size = 0;
	table->capacity = DEFAULT_TABLE_SIZE;
	table->body = itable_body_create(table->capacity);
	return (table);
}
