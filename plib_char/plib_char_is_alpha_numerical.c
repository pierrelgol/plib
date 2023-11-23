/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plib_char_is_alpha_numerical.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 12:03:24 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/11/23 12:03:25 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

int	plib_char_is_alpha_numerical(int ch)
{
	return (plib_char_is_alpha(ch) || plib_char_is_digit(ch));
}
