/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_content_search.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 11:36:05 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/09 11:36:05 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

char	*file_content_search(t_file *file, char *sub)
{
	if (!file || !sub || !file->content)
		return (0);
	return (string_search(file->content, sub));
}
