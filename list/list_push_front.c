/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_push_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 11:53:47 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/05 11:53:48 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

t_list *list_push_front(t_list **self, t_list *node)
{
	if (!self)
		return (0);
	if (!*self)
		(*self) = node;
	else
	{
		node->next = (*self);
		(*self) = node;
	}
	return (node);
}
