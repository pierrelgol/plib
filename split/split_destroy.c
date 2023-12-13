/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_destroy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 08:53:47 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/11 08:53:47 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

char	**split_destroy(char **split)
{
	unsigned int	i;

	if (!split)
		return (0);
	i = 0;
	while (split[i])
		free(split[i++]);
	free(split[i]);
	return (0);
}
