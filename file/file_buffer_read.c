/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_buffer_read.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 17:20:23 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/30 17:20:24 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

int	file_buffer_read(t_file *file)
{
	t_buffer	*buffer;

	buffer = file->buffer;
	if (buffer->rindex <= buffer->count)
		return (buffer->data[buffer->rindex++]);
	else
		return (0);
}
