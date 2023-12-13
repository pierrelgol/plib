/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_remove_front.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 20:11:01 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/04 20:11:32 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

void	*list_remove_front(t_list **self)
{
	t_list	*temp;
	void	*data;

	if (!self || !*self)
		return (0);
	temp = (*self);
	data = temp->data;
	(*self) = (*self)->next;
	memory_dealloc(temp);
	return (data);
}
