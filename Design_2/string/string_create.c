/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 12:44:15 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/01 12:44:15 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

char	*string_create(unsigned int size)
{
	return (memory_alloc(size, sizeof(char)));
}
