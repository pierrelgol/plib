/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logging_allocator_destroy.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 13:14:59 by pollivie          #+#    #+#             */
/*   Updated: 2024/01/30 13:15:00 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/plib.h"

static t_log_entry *logging_search_list(struct s_allocator *allocator, intptr_t *p)
{
    t_log_entry *entry;
    t_log_entry  current;
    t_list      *list;

    if (!p)
	return (0);
    list = allocator->history;
    current.ptr = (intptr_t)p;
    while (list != 0)
    {
	entry = list->data;
        if (!entry)
        	list = list->next;
        else if (entry->ptr == (intptr_t)*p || entry->ptr == (intptr_t)p)
        {
            list->data = 0;
	    return (entry);
        }
        else
        	list = list->next;
    }
    return (0);
}

void *logging_allocator_destroy(struct s_allocator *allocator, void *p)
{
    struct s_allocator *parent;
    struct s_allocator *private;
    t_log_entry *entry;

    entry = 0;
    parent = allocator->parent_allocator;
    private = allocator->private_allocator;
    entry = logging_search_list(allocator, p);
    if (entry == 0)
        print_fmt("destroy : Unkown bytes in %p\n",p);
    else
    {
        allocator->bytes_dealloced += entry->bytes;
        print_fmt("destroy : %u bytes in %p\n",entry->bytes, entry->ptr);
        private->destroy(private, entry);
    }
    parent->destroy(parent, p);
    return (0);
}
