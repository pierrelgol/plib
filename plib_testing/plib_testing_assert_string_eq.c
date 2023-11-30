/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plib_testing_assert_string_eq.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 17:24:50 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/11/23 17:24:51 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"
#include <stdio.h>
#include <string.h>

int	plib_testing_assert_string_eq(char *str1, char *str2, char *name)
{
	int	result;

	result = strcmp(str1, str2);
	fprintf(stdout, "%16s : %s\n",name, (result == 0 ? "pass" : "fail"));
	return (result == 0);
}
