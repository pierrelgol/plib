/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_remove_front.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 12:44:53 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/01 12:44:53 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

char	*string_remove_front(char *source, char *to_remove)
{
	char	*result;

	if (!source || !to_remove)
		return (0);
	result = string_slice(source, string_length(to_remove),
			string_length(source));
	if (!result)
		return (0);
	return (result);
}
