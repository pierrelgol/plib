/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_pop_at.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 11:53:29 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/05 11:53:40 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

t_list	*list_pop_at(t_list **list, unsigned int index)
{
	t_list	*prev;
	t_list	*curr;

	if (!list || !*list)
		return (0);
	if (index == 0)
		return (list_pop_front(list));
	else if (index >= list_length(*list))
		return (list_pop_back(list));
	else
	{
		curr = (*list);
		prev = curr;
		while (index--)
		{
			prev = curr;
			curr = curr->next;
		}
		prev->next = curr->next;
		curr->next = 0;
		return (curr);
	}
}

