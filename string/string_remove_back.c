/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_remove_back.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 12:45:03 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/01 12:45:05 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

char	*string_remove_back(char *source, char *to_remove)
{
	char	*result;

	if (!source || !to_remove)
		return (0);
	result = string_slice(source, 0, string_length(to_remove));
	if (!result)
		return (0);
	return (result);
}
