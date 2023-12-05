/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_push_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 11:53:54 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/05 11:53:55 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

t_list	*list_push_back(t_list **list, t_list *node)
{
	t_list	*temp;

	if (!list)
		return (0);
	if (!*list)
		(*list) = node;
	else
	{
		temp = (*list);
		while (temp->next)
			temp = temp->next;
		temp->next = node;
	}
	return (node);
}

