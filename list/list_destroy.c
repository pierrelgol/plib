/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_destroy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 20:06:52 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/04 20:06:53 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

t_list	*list_destroy(t_list *list)
{
	t_list	*temp;

	if (!list)
		return (0);
	temp = list;
	while (temp)
	{
		temp = list;
		list = list->next;
		temp = memory_destroy(temp);
	}
	return (0);
}
