/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plib_table_destroy.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 09:25:51 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/11/23 09:25:52 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

void	plib_table_destroy(t_table *self)
{
	plib_memory_dealloc(self->body);
	plib_memory_dealloc(self);
}
