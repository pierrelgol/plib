/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_content_clone.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 11:26:21 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/09 11:27:35 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

t_file	*file_content_clone(t_file *file, char *content)
{
	if (!file || !content)
		return (0);
	file->content = string_clone(content);
	return (file);
}
