/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_length.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 20:47:55 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/04 20:47:56 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../plib.h"

unsigned int list_length(t_list *list)
{
	if (!list)
		return (0);
	return (1 + list_length(list->next));
}
