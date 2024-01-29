/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 10:18:18 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/12 10:18:18 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/plib.h"

static t_list	*list_rotate_left(t_list **list, unsigned int shift)
{
	unsigned int	length;
	t_list			*temp;

	if (!list || !*list)
		return (0);
	length = list_length(*list);
	shift %= length;
	if (shift == 0)
		return (*list);
	while (shift--)
	{
		temp = list_pop_at(list, 0);
		list_push_at(list, temp, length);
	}
	return (*list);
}

static t_list	*list_rotate_right(t_list **list, unsigned int shift)
{
	unsigned int	length;
	t_list			*temp;

	if (!list || !*list)
		return (0);
	length = list_length(*list);
	shift %= length;
	if (shift == 0)
		return (*list);
	while (shift--)
	{
		temp = list_pop_at(list, length);
		list_push_at(list, temp, 0);
	}
	return (*list);
}

t_list	*list_rotate(t_list **list, int shift)
{
	if (!list)
		return (0);
	else if (shift == 0)
		return (0);
	else if (shift < 0)
		return (list_rotate_left(list, shift));
	else
		return (list_rotate_right(list, shift));
}
