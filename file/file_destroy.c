/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_destroy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 11:04:38 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/09 11:04:39 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

t_file	*file_destroy(t_file *file)
{
	if (!file)
		return (0);
	if (bit_is_set(file->flag, IS_OPEN))
		file_close(file->in);
	if (file->name)
		string_destroy(file->name);
	if (file->path)
		string_destroy(file->path);
	if (file->content)
		string_destroy(file->content);
	return (memory_dealloc(file));
}
