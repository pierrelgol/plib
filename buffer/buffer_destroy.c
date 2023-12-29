/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_destroy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 14:29:02 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/29 14:29:03 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

t_buffer	*buffer_destroy(t_buffer *buffer)
{
	if (!buffer)
		return (0);
	if (buffer->data != 0)
		memory_destroy(buffer->data);
	return (memory_destroy(buffer));
}
