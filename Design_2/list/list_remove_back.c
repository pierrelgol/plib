/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_remove_back.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 20:39:28 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/04 20:39:29 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

void	*list_remove_back(t_list **self)
{
	t_list	*prev;
	t_list	*curr;
	void	*data;

	if (!self || !*self)
		return (0);
	curr = (*self);
	prev = curr;
	while (curr->next)
	{
		prev = curr;
		curr = curr->next;
	}
	data = curr->data;
	prev->next = 0;
	memory_dealloc(curr);
	return (data);
}
