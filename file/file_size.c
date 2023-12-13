/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_size.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 11:14:53 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/09 11:14:54 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

int	file_size(char *path)
{
	int		fd;
	int		length;
	int		rbytes;
	char	*buffer;

	if (!path)
		return (0);
	fd = file_open(path, O_RDONLY);
	if (fd < 0)
		return (-1);
	length = 0;
	rbytes = READ_SIZE;
	buffer = (char [READ_SIZE]){0};
	while (rbytes == READ_SIZE)
	{
		rbytes = read(fd, buffer, READ_SIZE);
		length += rbytes;
	}
	fd = file_close(fd);
	return (length);
}
