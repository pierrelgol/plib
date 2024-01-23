/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_clone_name.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 11:25:49 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/09 11:27:40 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

t_file	*file_clone_name(t_file *file, char *name)
{
	if (!file || !name)
		return (0);
	file->name = string_clone(file->allocator, name);
	return (file);
}
