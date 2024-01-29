/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string_nl.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 09:12:23 by plgol.perso       #+#    #+#             */
/*   Updated: 2024/01/08 09:18:42 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/plib.h"

int	print_string_nl(int fd, char *string)
{
	if (!string || fd < 0)
		return (0);
	return (write(fd, string, string_length(string)) + write(fd, "\n", 1));
}
