/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logging_allocator_realloc.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 13:15:18 by pollivie          #+#    #+#             */
/*   Updated: 2024/01/30 13:15:18 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../include/plib.h"
#include <stdint.h>


void *logging_allocator_realloc(struct s_allocator *allocator, void *ptr, size_t old ,size_t size)
{
	return (allocator->parent_allocator->realloc(allocator->parent_allocator, ptr, old, size));
}
