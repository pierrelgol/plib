/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plib_list_destroy.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 09:16:42 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/11/23 09:16:48 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

void	plib_list_destroy(t_list **list)
{
	if (list == NULL)
		return ;
	while (*list != NULL)
		plib_list_remove(list, *list);
}
