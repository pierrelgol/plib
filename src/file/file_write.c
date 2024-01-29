/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_write.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 11:12:44 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/09 11:12:44 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/plib.h"


int	file_write(int fd, char *buffer, unsigned int size)
{
	int	wbytes;

	wbytes = write(fd, buffer, size);
	return (wbytes);
}
