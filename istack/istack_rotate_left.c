/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   istack_rotate_left.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 15:57:58 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/14 15:57:59 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

void	istack_rotate_left(t_istack *s, int shift)
{
	int	rcount;
	int	bcount;
	int	*temp;

	rcount = shift % s->count;
	if (rcount == 0)
		return ;
	bcount = rcount * sizeof(int);
	temp = memory_create(bcount, 1);
	if (!temp)
		return ;
	memory_copy(temp, s->data, bcount);
	memory_move(s->data, s->data + rcount, (s->count - rcount) * sizeof(int));
	memory_copy(s->data + (s->count - rcount), temp, bcount);
	memory_destroy(temp);
}
