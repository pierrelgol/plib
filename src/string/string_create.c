/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 13:22:10 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/10 13:22:11 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/plib.h"

char	*string_create(struct s_allocator *allocator, size_t size)
{
	char	*new_string;

	new_string = allocator->create(allocator, size * sizeof(char));
	return (new_string);
}
