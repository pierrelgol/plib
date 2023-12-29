/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_ptr_peek_at.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 16:20:46 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/29 16:20:47 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

void	*vector_ptr_peek_at(t_vector *vector, int index)
{
	void	**ptr;

	ptr = vector_peek_at(vector, index);
	return (*ptr);
}
