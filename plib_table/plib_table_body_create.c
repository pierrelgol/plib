/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plib_table_body_create.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 09:26:40 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/11/23 09:26:42 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

t_entry	*plib_table_body_create(unsigned int capacity)
{
	return ((t_entry *)plib_memory_alloc(capacity, sizeof(t_entry)));
}
