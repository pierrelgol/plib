/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_pop_back.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 11:53:20 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/05 11:53:21 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

t_list	*list_pop_back(t_list **self)
{
	t_list	*prev;
	t_list	*curr;

	if (!self || !*self)
		return (0);
	curr = (*self);
	prev = curr;
	while (curr->next)
	{
		prev = curr;
		curr = curr->next;
	}
	prev->next = 0;
	curr->next = 0;
	return (curr);
}
