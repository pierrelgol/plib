/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 09:09:31 by plgol.perso       #+#    #+#             */
/*   Updated: 2024/01/08 09:18:32 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/plib.h"

int	print_string(int fd, char *string)
{
	if (!string || fd < 0)
		return (0);
	return (write(fd, string, string_length(string)));
}
