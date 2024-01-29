/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_dealloc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 11:54:11 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/01 11:54:11 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/plib.h"


void	*memory_destroy(void *ptr)
{
	if (DBG)
		print_fmt("[LOG]memory_destroy(%p)\n",ptr);
	if (!ptr)
		return (0);
	free(ptr);
	return (0);
}
