/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plib_io_file_split_token.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 14:33:48 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/11/28 14:33:49 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

char	**plib_io_file_split_token(t_file *self, char *charset)
{
	char **result;

	result = NULL;
	result = plib_string_split(self->content, charset);
	return (result);
}
