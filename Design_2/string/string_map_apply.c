/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_map_apply.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 15:08:22 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/01 15:08:23 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

char	*string_map_apply(char *str, int (*f)(int ch))
{
	int	i;

	if (!str || !f)
		return (0);
	i = 0;
	while (str[i])
	{
		str[i] = (char)f(str[i]);
		++i;
	}
	return (str);
}
