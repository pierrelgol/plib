/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plib_io_file_split_list_chunk.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 15:30:18 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/11/28 15:30:19 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

t_list *plib_io_file_split_list_chunk(t_file *self, int chunk_size)
{
	t_list	*head;
	char	**split;
	int	i;

	i = 0;
	split = plib_io_file_split_chunk(self, chunk_size);
	if (!split)
		return (NULL);
	head = plib_list_create(split[i++]);
	while(split[i])
		plib_list_insert_back(head, split[i++]);
	plib_memory_dealloc(split);
	return (head);
}
