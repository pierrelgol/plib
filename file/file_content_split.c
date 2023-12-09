/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_content_split.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 11:37:12 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/09 11:37:13 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

char	**file_content_split(t_file *file, int ch)
{
	if (!file || !file->content)
		return (0);
	return (string_split(file->content, ch));
}
