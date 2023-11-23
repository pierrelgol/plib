/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plib_char_is_in_range.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 12:03:04 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/11/23 12:03:05 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

int	plib_char_is_in_range(int lbound, int ubound, int ch)
{
	return (ch >= lbound && ch <= ubound);
}
