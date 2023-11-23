/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plib_table_entry_get.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 09:26:10 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/11/23 09:26:12 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

void	*plib_table_entry_get(t_table *self, char *key)
{
	int	index;

	index = plib_table_body_find_empty(self, key);
	if (self->body[index].key != NULL)
		return (self->body[index].value);
	else
		return (NULL);
}
