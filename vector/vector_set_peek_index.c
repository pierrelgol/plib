/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_set_peek_index.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 16:25:47 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/29 16:25:49 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

int	vector_set_peek_index(t_vector *vector, int index)
{
	if (index < 0 || index > vector->item_count)
		return (0);
	vector->peek_index = index;
	return (vector->peek_index);
}
