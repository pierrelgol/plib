/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_read.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 11:10:50 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/09 11:10:51 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

int	file_read(int fd, char *buffer, unsigned int size)
{
	int	rbytes;

	if (!buffer || fd < 0)
		return (-1);
	rbytes = read(fd, buffer, size);
	return (rbytes);
}
