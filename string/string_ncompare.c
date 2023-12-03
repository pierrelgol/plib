/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_ncompare.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 12:43:50 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/01 12:43:51 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

int	string_ncompare(char *str1, char *str2, unsigned int n)
{
	if (!str1 || !str2 || !n)
		return (0);
	return (memory_compare(str1, str2, n));
}
