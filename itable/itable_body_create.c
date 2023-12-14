/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itable_body_create.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 16:06:33 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/14 16:06:33 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

t_ientry	*itable_body_create(unsigned int capacity)
{
	return ((t_ientry *)memory_create(capacity, sizeof(t_entry)));
}
