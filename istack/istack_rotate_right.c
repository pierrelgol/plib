/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   istack_rotate_right.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 15:58:04 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/14 15:58:04 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

void	istack_rotate_right(t_istack *s, int shift)
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
	memory_copy(temp, s->data + (s->count - rcount), bcount);
	memory_move(s->data + rcount, s->data, (s->count - rcount) * sizeof(int));
	memory_copy(s->data, temp, bcount);
	memory_destroy(temp);
}
