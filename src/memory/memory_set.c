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

#include "../../include/plib.h"


void	*memory_set(void *m1, char ch, size_t n)
{
	unsigned char	*ptr_m1;

	if (DBG)
		print_fmt("[LOG]memory_compare(%p, %c, %d)\n",m1,ch,n);
	ptr_m1 = m1;
	while (n--)
		*ptr_m1++ = (unsigned char)ch;
	return (m1);
}
