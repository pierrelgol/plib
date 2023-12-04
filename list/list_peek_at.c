/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_peek_at.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 11:11:24 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/04 11:11:24 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

void	*list_peek_at(t_list *list, unsigned int index)
{
	if (index == 0)
		return (list->head->data);
	else if (index < list_size(list))
		return (list_node_at(list->head, index)->data);
	else
		return (list->tail->data);
}
