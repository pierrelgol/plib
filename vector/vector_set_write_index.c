/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_set_write_index.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 16:26:29 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/29 16:26:30 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

int	vector_set_write_index(t_vector *vector, int index)
{
	if (index < 0 || index > vector->items_size)
		return (0);
	vector->write_index = index;
	return (vector->write_index);
}
