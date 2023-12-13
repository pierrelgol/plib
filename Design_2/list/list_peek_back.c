/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_peek_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 10:58:32 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/05 10:58:34 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

void	*list_peek_back(t_list **self)
{
	t_list	*curr;

	if (!self || !*self)
		return (0);
	curr = (*self);
	while (curr->next)
		curr = curr->next;
	return (curr->data);
}
