/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itable_body_find_empty.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 16:07:32 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/14 16:07:33 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

unsigned int	itable_body_find_empty(t_itable *table, char *key)
{
	int	index;

	index = itable_hash(key) % table->capacity;
	while (table->body[index].key != NULL
		&& string_compare(table->body[index].key, key) != 0)
		index = (index + 1) % table->capacity;
	return (index);
}
