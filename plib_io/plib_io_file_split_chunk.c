/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plib_io_file_split_chunk.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 14:52:05 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/11/28 14:52:06 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

static void plib_io_free_tab(char **tab, int index)
{
	int i;

	i = 0;
	while (i < index)
		plib_memory_dealloc(tab[i++]);
	plib_memory_dealloc(tab);
}

char **plib_io_file_split_chunk(t_file *self, int chunk_size)
{
	char **split;
	int	nchunk;
	int	i;

	if (chunk_size > self->count)
		return (NULL);
	nchunk = self->count / chunk_size;
	split = plib_memory_alloc(nchunk + 1, sizeof(char *));
	i = 0;
	while (i < nchunk)
	{
		split[i] = plib_memory_alloc(chunk_size + 1, sizeof(char));
		if (!split[i])
			plib_io_free_tab(split, i);
		plib_memory_copy(split[i], &self->content[i * chunk_size], chunk_size);
		++i;
	}
	return (split);
}
