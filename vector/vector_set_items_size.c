/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_set_items_size.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 16:27:52 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/29 16:27:54 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

int	vector_set_items_size(t_vector *vector, int size)
{
	if (size < 0 || size > vector->items_size)
		return (0);
	vector->items_size = size;
	return (vector->items_size);
}
