/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_concat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 11:34:50 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/05 11:34:52 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

t_list	*list_concat(t_list **dstl, t_list **srcl)
{
	t_list	*dtail;
	t_list	*shead;

	if (!dstl || !srcl || !*dstl || !*srcl)
		return (0);
	dtail = list_get_tail(dstl);
	shead = list_get_head(srcl);
	dtail->next = shead;
	return ((*dstl));
}
