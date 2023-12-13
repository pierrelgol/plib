/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 13:22:10 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/10 13:22:11 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

char	*string_create(unsigned int size)
{
	char	*new_string;

	new_string = malloc(size * sizeof(char));
	if (!new_string)
		return (0);
	string_set(new_string, 0x00, size);
	return (new_string);
}
