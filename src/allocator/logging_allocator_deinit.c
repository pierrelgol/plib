/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logging_allocator_deinit.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 14:08:14 by pollivie          #+#    #+#             */
/*   Updated: 2024/01/30 14:08:15 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/plib.h"

void *logging_allocator_deinit(struct s_allocator *self)
{
	struct s_allocator *private;
	t_list	*list;
	t_log_entry *entry;

	if (!self)
		return (0);
	private = self->private_allocator;
	if (self->file != 0)
		file_destroy(self->file);
	if (self->history != 0)
	{
		list = self->history;
		while (list)
		{
			entry = list->data;
			if (entry != 0)
				private->destroy(private, entry);
			list = list->next;
		}
		list_destroy(private, self->history);
	}
	print_fmt("Bytes allocated   : %u\n",self->bytes_alloced);
	print_fmt("Bytes deallocated : %u\n",self->bytes_dealloced);
	private->destroy(private, self);
	heap_deinit(private);
	return (0);
}

