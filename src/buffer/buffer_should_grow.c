/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_should_grow.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 14:54:05 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/29 14:54:07 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/plib.h"

void	buffer_should_grow(t_buffer *buffer, int size)
{
	if (buffer->capacity <= (buffer->count + size))
		buffer_growth(buffer);
}
