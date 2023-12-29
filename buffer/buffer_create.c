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

t_buffer	*buffer_create(void)
{
	t_buffer	*buffer;

	buffer = memory_create(1, sizeof(t_buffer));
	if (!buffer)
		return (0);
	buffer->data = memory_create(BUFFER_DEFAULT_CAPACITY + 1, sizeof(char));
	if (!buffer->data)
		return (buffer_destroy(buffer));
	buffer->capacity = BUFFER_DEFAULT_CAPACITY;
	buffer->count = 0;
	buffer->rindex = 0;
	return (buffer);
}
