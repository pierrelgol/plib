/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena_destroy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 11:25:53 by pollivie          #+#    #+#             */
/*   Updated: 2024/01/23 11:25:54 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

void *arena_destroy(struct s_allocator *self, void *ptr)
{
	(void)self;
	(void)ptr;
	return (0);
}

