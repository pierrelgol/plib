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
	if (!table)
		return ;
	if (table->body != 0)
		memory_destroy(table->body);
	memory_destroy(table);
}
