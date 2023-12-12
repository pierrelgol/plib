/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 20:27:38 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/10 20:27:39 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

static char	*string_rotate_left(char *str, unsigned int n)
{
	unsigned int	len;
	char			*temp;

	if (!str)
		return (0);
	len = string_length(str);
	n %= len;
	if (n == 0 || len <= 1)
		return (str);
	temp = string_clone(str);
	temp[n] = '\0';
	string_move(str, str + n, len - n);
	str[len - n] = '\0';
	string_concat(str, temp, n);
	string_destroy(temp);
	return (str);
}

static char	*string_rotate_right(char *str, unsigned int n)
{
	unsigned int	len;
	char			*temp;

	if (!str)
		return (0);
	len = string_length(str);
	n %= len;
	if (n == 0 || len <= 1)
		return (str);
	temp = string_clone(str);
	string_move(str + n, str, len - n);
	string_copy(str, temp + len - n, n);
	str[len] = '\0';
	string_destroy(temp);
	return (str);
}

char	*string_rotate(char *str, int shift)
{
	if (shift < 0)
		return (string_rotate_left(str, shift));
	else
		return (string_rotate_right(str, shift));
}
