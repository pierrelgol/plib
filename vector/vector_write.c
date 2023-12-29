/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_write.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 16:25:03 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/29 16:25:03 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

int	vector_write(t_vector *vector, void *elem)
{
	int	bytes;

	if (vector->write_index > vector->item_count)
		return (0);
	bytes = vector->item_width;
	memory_copy(&vector->items[vector->write_index++], elem, bytes);
	return (bytes);
}
