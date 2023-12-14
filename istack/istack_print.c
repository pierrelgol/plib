/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   istack_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 15:58:10 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/14 15:58:12 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"
#include <stdio.h>

void	istack_print(t_istack *stack)
{
	int	i;

	i = 0;
	while (i <= stack->count)
		printf("%d,", stack->data[i++]);
}
