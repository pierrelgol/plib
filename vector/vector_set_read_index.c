/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_set_read_index.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 16:26:04 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/29 16:26:05 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

int	vector_set_read_index(t_vector *vector, int index)
{
	if (index < 0 || index > vector->item_count)
		return (0);
	vector->read_index = index;
	return (vector->read_index);
}
