/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_shrink.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 16:22:54 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/29 16:22:55 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

void	vector_shrink(t_vector *vector)
{
	int	bytes;

	bytes = (vector->items_size * vector->item_width) / VECTOR_GROWTH_RATE;
	vector->items = memory_realloc(vector->items, bytes);
	vector->items_size /= VECTOR_GROWTH_RATE;
}
