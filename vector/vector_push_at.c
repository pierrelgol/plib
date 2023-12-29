/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_push_at.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 16:19:33 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/29 16:19:33 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

static void	*vector_push_front(t_vector *vector, void *element)
{
	int	bytes;

	bytes = vector->item_count * vector->item_width;
	memory_move(vector->items + vector->item_width, vector->items, bytes);
	memory_copy(vector->items, element, vector->item_width);
	vector->item_count++;
	if (vector->item_count == vector->items_size)
		vector_growth(vector);
	return (element);
}

static void	*vector_push_back(t_vector *vector, void *element)
{
	int	end;

	end = (vector->item_count * vector->item_width);
	memory_copy(&vector->items[end], element, vector->item_width);
	vector->item_count++;
	if (vector->item_count == vector->items_size)
		vector_growth(vector);
	return (element);
}

void	*vector_push_at(t_vector *vector, void *element, int index)
{
	void	*at;
	int		bytes;

	if (index < 0 || index > vector->item_count)
		return (0);
	if (index == 0)
		return (vector_push_back(vector, element));
	else if (index == vector->item_count)
		return (vector_push_front(vector, element));
	else
	{
		at = vector->items + (index * vector->item_width);
		bytes = (vector->item_count - index) * vector->item_width;
		memory_move(at + vector->item_width, at, bytes);
		memory_copy(at, element, vector->item_width);
		vector->item_count++;
	}
	if (vector->item_count == vector->items_size)
		vector_growth(vector);
	return (element);
}
