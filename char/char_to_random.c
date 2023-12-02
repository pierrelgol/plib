/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_to_random.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 21:29:53 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/11/30 21:29:53 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"
#include <time.h>

int	char_to_random(int ch)
{
	static int seed = 5731;
	ch++;
	ch = (ch << 13) ^ ch + seed++;
	ch = (ch * (ch * ch * 15731 + 789221) + 1376312589) & 0x7fffffff;
	return ((unsigned char)ch);
}
