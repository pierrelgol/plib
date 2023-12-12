/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_create.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 10:43:40 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/09 10:43:41 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

t_file	*file_create(void)
{
	t_file	*file;

	file = memory_alloc(1, sizeof(t_file));
	if (!file)
		return (0);
	file->flag = bit_set_bit(file->flag, IS_VALID);
	return (file);
}
