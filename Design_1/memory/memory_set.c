/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_set.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 12:09:50 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/01 12:09:51 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

void	*memory_set(void *m1, int ch, unsigned int n)
{
	unsigned char	*ptr_m1;

	if (!m1 || !n)
		return (0);
	ptr_m1 = m1;
	while (n--)
		*ptr_m1++ = (unsigned char)ch;
	return (m1);
}
