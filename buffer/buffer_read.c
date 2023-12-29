/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_read.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 14:39:28 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/29 14:39:28 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

char	buffer_read(t_buffer *buffer)
{
	if (buffer->rindex >= buffer->count)
		return (0);
	return (buffer->data[buffer->rindex++]);
}
