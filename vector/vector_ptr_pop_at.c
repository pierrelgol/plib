/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_ptr_pop_at.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 16:20:00 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/29 16:20:01 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

void	*vector_ptr_pop_at(t_vector *vector, int index)
{
	void	**ptr;

	ptr = vector_pop_at(vector, index);
	return (*ptr);
}
