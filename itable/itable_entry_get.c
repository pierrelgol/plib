/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itable_entry_get.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 16:06:46 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/14 16:06:46 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

long	itable_entry_get(t_itable *table, char *key)
{
	int	index;

	index = itable_body_find_empty(table, key);
	if (table->body[index].key != NULL)
		return (table->body[index].value);
	else
		return (0);
}
