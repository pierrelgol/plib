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
	char	*old_data;
	char	*new_data;

	old_data = buffer->data;
	new_data = memory_create(buffer->capacity * BUFFER_GROWTH_RATE + 1, 1);
	if (!new_data)
		return ;
	else
		memory_copy(new_data, old_data, buffer->capacity * sizeof(char));
	buffer->data = new_data;
	buffer->capacity = buffer->capacity * BUFFER_GROWTH_RATE;
	memory_destroy(old_data);
}
