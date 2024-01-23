/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_destroy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 09:25:51 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/05 10:47:28 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

void	table_destroy(t_table *table)
{
	struct s_allocator *allocator;

	if (!table)
		return ;
	allocator = table->allocator;
	if (table->body != 0)
		allocator->destroy(allocator, table->body);
	allocator->destroy(allocator, table);
}
