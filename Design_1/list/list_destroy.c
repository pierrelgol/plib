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

t_list	*list_destroy(t_list *self)
{
	t_list	*temp;

	if (!self)
		return (0);
	temp = self;
	while (temp)
	{
		temp = self;
		self = self->next;
		temp = memory_destroy(temp);
	}
	return (0);
}
