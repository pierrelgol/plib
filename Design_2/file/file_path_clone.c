/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_path_clone.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 11:23:11 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/09 11:27:47 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

t_file	*file_path_clone(t_file *file, char *path)
{
	if (!file || !path)
		return (0);
	file->path = string_clone(path);
	return (file);
}
