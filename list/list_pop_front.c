/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_pop_front.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 11:53:10 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/05 11:53:15 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

t_list *list_pop_front(t_list **self)
{
	t_list *node;

	if (!self || !*self)
		return (0);
	node = (*self);
	(*self) = (*self)->next;
	node->next = 0;
	return (node);
}
