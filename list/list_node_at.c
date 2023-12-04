/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_node_at.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 12:32:41 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/04 12:32:42 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

t_node	*list_node_at(t_node *head, unsigned int index)
{
	unsigned int	count;
	t_node			*temp;

	if (!head)
		return (0);
	temp = head;
	count = 0;
	while (temp && count < index)
	{
		temp = temp->next;
		++count;
	}
	return (temp);
}
