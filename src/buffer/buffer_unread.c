/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_unread.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 14:41:51 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/29 14:41:52 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/plib.h"

char	buffer_unread(t_buffer *buffer, char ch)
{
	if (buffer->rindex == 0)
		return (0);
	buffer->data[--buffer->rindex] = ch;
	return (ch);
}
