/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_read.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 16:24:55 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/29 16:24:55 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

void	*vector_read(t_vector *vector)
{
	if (vector->read_index > vector->item_count)
		return (0);
	return (&vector[vector->read_index++]);
}
