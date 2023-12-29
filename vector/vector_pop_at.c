/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_pop_at.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 16:19:40 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/29 16:19:41 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

static void	*vector_pop_front(t_vector *vector)
{
	void	*ptr;
	int		bytes;

	if (vector->item_count == 0)
		return (0);
	ptr = vector->items;
	vector->item_count--;
	bytes = vector->item_count * vector->item_width;
	memory_move(vector->items, vector->items + vector->item_width, bytes);
	return (ptr);
}

static void	*vector_pop_back(t_vector *vector)
{
	void	*ptr;

	if (vector->item_count == 0)
		return (0);
	ptr = vector->items + ((vector->item_count - 1) * vector->item_width);
	vector->item_count--;
	return (ptr);
}

void	*vector_pop_at(t_vector *vector, int index)
{
	void	*ptr;
	int		bytes;

	if (index < 0 || index > vector->item_count)
		return (0);
	if (index == 0)
		return (vector_pop_front(vector));
	if (index == vector->item_count)
		return (vector_pop_back(vector));
	ptr = vector->items + (index * vector->item_width);
	bytes = (vector->item_count - index - 1) * vector->item_width;
	memory_move(ptr, ptr + vector->item_width, bytes);
	vector->item_count--;
	return (ptr);
}
