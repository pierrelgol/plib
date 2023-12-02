/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_rotate_left.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 12:45:22 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/01 12:45:23 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"
#include <string.h>

char	*string_rotate_left(char *str, unsigned int n)
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
	temp[n] = '\0';
	memory_move(str, str + n, length - n);
	str[length - n] = '\0';
	string_concat(str, temp);
	string_destroy(temp);
	return (str);
}
