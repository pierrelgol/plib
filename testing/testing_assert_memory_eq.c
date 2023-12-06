/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing_assert_memory_eq.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 17:29:56 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/06 21:05:12 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"
#include <stdio.h>
#include <string.h>

int	testing_assert_memory_eq(void *m1, void *m2, int n, char *name)
{
	int	result;

	result = memory_compare(m1, m2, n);
	if (result)
		fprintf(stdout, "%16s : %s\n", name, "pass");
	else
		fprintf(stdout, "%16s : %s\n", name, "fail");
	return (result == 0);
}
