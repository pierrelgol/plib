/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_close.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 11:07:21 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/09 11:07:22 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/plib.h"

int	file_close(int fd)
{
	if (fd < 0)
		return (-1);
	return (close(fd));
}
