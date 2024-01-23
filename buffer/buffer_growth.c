/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_growth.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 14:47:58 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/29 14:48:01 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

void	buffer_growth(t_buffer *buffer)
{
	size_t prev;
	size_t next;

	prev = buffer->capacity;
	next = prev * BUFFER_GROWTH_RATE;
	struct s_allocator *allocator = buffer->allocator;
	buffer->data = allocator->realloc(allocator, buffer->data,prev, next + 1);
	buffer->capacity = next;
}
