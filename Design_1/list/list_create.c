/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_create.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 19:59:26 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/04 19:59:29 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

t_list	*list_create(void)
{
	t_list	*list;

	list = memory_create(1, sizeof(*list));
	if (!list)
		return (0);
	list->next = 0;
	list->data = 0;
	return (list);
}
