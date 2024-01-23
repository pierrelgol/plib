/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_destroy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 13:24:35 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/10 13:24:36 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

char	*string_destroy(struct s_allocator *allocator, char *str)
{
	if (!str)
		return (0);
	allocator->destroy(allocator, str);
	return (0);
}
