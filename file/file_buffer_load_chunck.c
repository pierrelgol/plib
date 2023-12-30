/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_buffer_load_chunck.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 16:55:53 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/30 16:55:54 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

int	file_buffer_load_chunk(t_file *file, int chunk_size)
{	
	int	bytes_read;
	t_buffer *buffer;

	if (chunk_size <= 0)
		return (0);
	buffer = file->buffer;
	bytes_read = READ_SIZE;
	while((buffer->count + chunk_size + 1) > buffer->capacity)
		buffer_growth(file->buffer);
	bytes_read = file_read(file->in, &buffer->data[buffer->count], chunk_size);
	buffer->count += bytes_read;
	buffer->data[buffer->count] = 0x00;
	return (bytes_read);
}
