/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_write.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 14:57:05 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/29 14:57:06 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/plib.h"

void	buffer_write(t_buffer *buffer, char ch)
{
	buffer_should_grow(buffer, sizeof(char));
	buffer->data[buffer->count++] = ch;
}
