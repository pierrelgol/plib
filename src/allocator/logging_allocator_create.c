/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logging_allocator_create.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 13:14:50 by pollivie          #+#    #+#             */
/*   Updated: 2024/01/30 13:14:51 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/plib.h"
#include <stdint.h>


void *logging_allocator_create(struct s_allocator *allocator, size_t size)
{
    struct s_allocator *parent;
    struct s_allocator *private;
    t_log_entry    *entry;
    intptr_t *ptr;

    parent = allocator->parent_allocator;
    private = allocator->private_allocator;
    ptr = parent->create(parent, size);
    if (!ptr)
    {
        print_fmt("allocation : %u bytes -> [FAIL] return %p\n",size, 0);
        return (0);
    }
    allocator->bytes_alloced += size;
    entry = private->create(private, sizeof(t_log_entry));
    entry->bytes = size;
    entry->ptr = (intptr_t)ptr;
    list_insert_at(private, &allocator->history, entry, allocator->count++);
    print_fmt("allocation : %u bytes -> [OK] return %p\n",size, ptr);
    return (ptr);
}
