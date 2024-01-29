/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_entry_get.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 09:26:10 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/05 10:47:34 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/plib.h"

void	*table_entry_get(t_table *table, char *key)
{
	int	index;

	index = table_body_find_empty(table, key);
	if (table->body[index].key != NULL)
		return (table->body[index].value);
	else
		return (NULL);
}
