/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plib_writer_destroy.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 13:08:52 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/11/23 14:26:29 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

t_writer	*plib_writer_destroy(t_writer *self)
{
	return (plib_memory_dealloc(self));
}
