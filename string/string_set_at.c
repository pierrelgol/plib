/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_set_at.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 12:19:08 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/01 12:19:09 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

int	string_set_at(char *str, unsigned int index, int ch)
{
	if (index < 0u || index > string_length(str))
		return (-1);
	str[index] = (char)ch;
	return (1);
}
