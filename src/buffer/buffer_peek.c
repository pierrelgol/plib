/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_peek.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 14:45:02 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/29 14:45:04 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/plib.h"

char	buffer_peek(t_buffer *buffer)
{
	if (buffer->rindex >= buffer->count)
		return (-1);
	return (buffer->data[buffer->rindex]);
}
