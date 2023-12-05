/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_get_tail.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 11:34:22 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/05 11:34:23 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

t_list	*list_get_tail(t_list **self)
{
	t_list *temp;

	if (!self || !*self)
		return (0);
	temp = (*self);
	while (temp->next)
		temp = temp->next;
	return (temp);
}
