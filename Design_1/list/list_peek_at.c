/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_peek_at.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 11:00:05 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/05 11:00:07 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

static void	*list_peek_front(t_list **self)
{
	if (!self || !*self)
		return (0);
	return ((*self)->data);
}

static void	*list_peek_back(t_list **self)
{
	t_list	*curr;

	if (!self || !*self)
		return (0);
	curr = (*self);
	while (curr->next)
		curr = curr->next;
	return (curr->data);
}

void	*list_peek_at(t_list **list, unsigned int index)
{
	t_list	*curr;

	if (!list || !*list)
		return (0);
	if (index == 0)
		return (list_peek_front(list));
	else if (index >= list_length(*list))
		return (list_peek_back(list));
	else
	{
		curr = (*list);
		while (index--)
			curr = curr->next;
		return (curr->data);
	}
}
