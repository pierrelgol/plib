/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_rotate_right.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 12:45:29 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/01 12:45:30 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

char	*string_rotate_right(char *str, unsigned int n)
{
	unsigned int	length;
	char			*temp;

	if (!str)
		return (0);
	length = string_length(str);
	n %= length;
	if (n == 0)
		return (str);
	temp = string_clone(str);
	memory_move(str + n, str, length - n);
	memory_copy(str, temp + length - n, n);
	str[length] = '\0';
	string_destroy(temp);
	return (str);
}
