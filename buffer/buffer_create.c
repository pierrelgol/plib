/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 14:24:40 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/29 14:24:41 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

t_buffer	*buffer_create(struct s_allocator *allocator)
{
	t_buffer	*buffer;
	size_t		default_size;

	buffer = allocator->create(allocator, sizeof(t_buffer));
	if (!buffer)
		return (0);
	default_size = BUFFER_DEFAULT_CAPACITY;
	buffer->data = allocator->create(allocator, default_size);
	if (!buffer->data)
		return (buffer_destroy(buffer));
	buffer->allocator = allocator;
	buffer->capacity = BUFFER_DEFAULT_CAPACITY;
	buffer->count = 0;
	buffer->rindex = 0;
	return (buffer);
}
