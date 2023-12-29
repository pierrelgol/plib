/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_ptr_push_at.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 16:20:38 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/29 16:20:38 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

void	*vector_ptr_push_at(t_vector *vector, void *elem, int index)
{
	void	**ptr;

	ptr = vector_push_at(vector, elem, index);
	return (*ptr);
}
