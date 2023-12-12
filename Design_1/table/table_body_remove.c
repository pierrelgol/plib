/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_body_remove.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 09:26:49 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/05 10:47:02 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

void	table_body_remove(t_table *t, char *key)
{
	int	index;

	index = table_body_find_empty(t, key);
	if (t->body[index].key != NULL)
	{
		t->body[index].key = NULL;
		t->body[index].value = NULL;
		t->size--;
	}
}
