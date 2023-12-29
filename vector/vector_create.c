/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 16:19:17 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/29 16:19:18 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

t_vector	*vector_create(int esize)
{
	t_vector	*vector;

	vector = memory_create(1, sizeof(t_vector));
	if (!vector)
		return (0);
	vector->items = memory_create(VECTOR_DEFAULT_CAPACITY + 1, esize);
	if (!vector->items)
		return (vector_destroy(vector));
	vector->items_size = esize * VECTOR_DEFAULT_CAPACITY;
	vector->item_count = 0;
	vector->item_width = esize;
	vector->peek_index = 0;
	vector->read_index = 0;
	vector->write_index = 0;
	return (vector);
}
