/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_buffer_destroy.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 16:48:59 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/30 16:49:00 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/plib.h"

int	file_buffer_destroy(t_file *file)
{
	if (file->buffer != 0)
	{
		buffer_destroy(file->buffer);
		return (1);
	}
	return (0);
}
