/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itable_destroy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 16:06:13 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/14 16:06:17 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

void	itable_destroy(t_itable *table)
{
	if (!table)
		return ;
	if (table->body != 0)
		memory_destroy(table->body);
	memory_destroy(table);
}
