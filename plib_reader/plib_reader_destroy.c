/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plib_reader_destroy.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 13:31:12 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/11/23 13:31:13 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

t_reader	*plib_reader_destroy(t_reader *self)
{
	return (plib_memory_dealloc(self));
}
