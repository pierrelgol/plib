/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_body_create.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 09:26:40 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/05 10:46:45 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

t_entry	*table_body_create(unsigned int capacity)
{
	return ((t_entry *)memory_alloc(capacity, sizeof(t_entry)));
}
