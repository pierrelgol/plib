/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itable_body_remove.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 16:07:19 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/14 16:07:19 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

void	itable_body_remove(t_itable *table, char *key)
{
	int	index;

	index = itable_body_find_empty(table, key);
	if (table->body[index].key != NULL)
	{
		table->body[index].key = NULL;
		table->body[index].value = 0;
		table->size--;
	}
}
