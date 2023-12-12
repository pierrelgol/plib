/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_contains.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 12:30:26 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/01 12:30:27 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

int	string_contains(char *str, char *sub)
{
	if (!str || !sub)
		return (0);
	return (string_search(str, sub) != 0);
}
