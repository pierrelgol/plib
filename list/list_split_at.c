/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_split_at.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 12:10:50 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/05 12:10:50 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../plib.h"

t_list	*list_split_at(t_list **self, unsigned int index)
{
	t_list	*prev;
	t_list	*split;

	if (!self || !*self)
		return (0);
	else if (index == 0)
		return (*self);
	else if (index >= list_length(*self))
		return (list_pop_back(self));
	else
	{
		split = (*self);
		while (index--)
		{
			prev = split;
			split = split->next;
		}
		prev->next = 0;
		return (split);
	}
}
