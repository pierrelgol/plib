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
	buffer->capacity = buffer->capacity * BUFFER_GROWTH_RATE;
	buffer->data = memory_realloc(buffer->data, buffer->capacity + 1);
}
