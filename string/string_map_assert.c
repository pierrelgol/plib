/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_map_assert.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 20:37:00 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/02 20:37:02 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int string_map_assert(char *str, int (*f)(int ch))
{
	if (!str || !f)
		return (-1);
	while (*str)
	{
		if (!f(*str))
			break;
		++str;
	}
	return (*str == '\0');
}
