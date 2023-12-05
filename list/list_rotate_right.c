/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_rotate_right.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 11:34:31 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/05 11:34:33 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

t_list *list_rotate_right(t_list **self, unsigned int shift)
{
	unsigned int length;
	t_list      *temp;

	if (!self || !*self)
		return (0);
	length = list_length(*self);
	shift %= length;
	if (shift == 0)
		return (*self);
	while (shift--)
	{
		temp = list_pop_back(self);
		list_push_front(self, temp);
	}
	return (*self);
}

