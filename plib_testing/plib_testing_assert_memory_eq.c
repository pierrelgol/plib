/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plib_testing_assert_memory_eq.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 17:29:56 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/11/23 17:29:57 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"
#include <stdio.h>
#include <string.h>

int	plib_testing_assert_memory_eq(void *m1, void *m2, int n, char *name)
{
	int	result;

	result = memcmp(m1, m2, n);
	fprintf(stdout, "%16s : %s\n",name, (result == 0 ? "pass" : "fail"));
	return (result == 0);
}
