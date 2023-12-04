/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_size.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 11:17:42 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/04 11:17:43 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

unsigned int	list_size(t_list *list)
{
	unsigned int	size;
	t_node			*temp;

	if (!list)
		return (0);
	size = 0;
	temp = list->head;
	while (temp)
	{
		temp = temp->next;
		++size;
	}
	return (size);
}
