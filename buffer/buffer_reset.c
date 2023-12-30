/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_reset.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 14:24:43 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/30 14:24:44 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

void	buffer_reset(t_buffer *buffer)
{	
	buffer->count = 0;
	buffer->rindex = 0;
	memory_set(buffer->data,0x00,buffer->capacity);
}
