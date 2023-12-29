/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_destroy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 16:19:25 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/29 16:19:25 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

t_vector	*vector_destroy(t_vector *vector)
{
	if (!vector)
		return (0);
	if (!vector->items)
		return (memory_destroy(vector));
	else
	{
		memory_destroy(vector->items);
		return (memory_destroy(vector));
	}
	return (0);
}
