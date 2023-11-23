/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plib_list_find_node.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 09:24:51 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/11/23 09:24:52 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

t_list	*plib_list_find_node(t_list *list, t_list *node)
{
	while (list)
	{
		if (list == node)
			break ;
		list = list->next;
	}
	return (list);
}
