/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_peek_at.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 16:19:47 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/29 16:19:48 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

void	*vector_peek_at(t_vector *vector, int index)
{
	if (index < 0 || index > vector->item_count)
		return (0);
	return (&vector->items[index]);
}
