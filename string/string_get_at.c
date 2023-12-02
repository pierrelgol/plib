/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_get_at.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 12:17:36 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/01 12:17:37 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

int	string_get_at(char *str, unsigned int index)
{
	if (!str || index < 0 || index >= string_length(str))
		return (-1);
	return (str[index]);
}
