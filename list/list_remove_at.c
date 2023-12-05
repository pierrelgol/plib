/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_remove_at.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 20:58:34 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/04 20:58:34 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

void	*list_remove_at(t_list **list, unsigned int index)
{
	t_list	*prev;
	t_list	*curr;
	void	*data;

	if (!list || !*list)
		return (0);
	if (index == 0)
		return (list_remove_front(list));
	else if (index >= list_length(*list))
		return (list_remove_back(list));
	else
	{
		curr = (*list);
		prev = curr;
		while (index--)
		{
			prev = curr;
			curr = curr->next;
		}
		data = curr->data;
		prev->next = curr->next;
		memory_dealloc(curr);
		return (data);
	}
}
