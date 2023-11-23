/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plib_list_find_data.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 09:18:14 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/11/23 09:18:16 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

t_list	*plib_list_find_data(t_list *list, void *data, t_comparator comp)
{
	while (list)
	{
		if (comp(list->data, data))
			break ;
		list = list->next;
	}
	return (list);
}
