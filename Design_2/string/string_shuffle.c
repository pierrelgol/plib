/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_shuffle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 12:47:17 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/01 12:47:18 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

char	*string_shuffle(char *str)
{
	unsigned int	length;
	char			seed[2];

	if (!str)
		return (0);
	length = string_length(str);
	if (length <= 1)
		return (str);
	seed[0] = str[0];
	seed[1] = str[length - 1];
	str = string_rotate_left(str, seed[0]);
	str = string_reverse(str);
	str = string_rotate_right(str, seed[1]);
	return (str);
}
