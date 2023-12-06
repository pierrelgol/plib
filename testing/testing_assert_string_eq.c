/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing_assert_string_eq.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 17:24:50 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/06 21:05:24 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"
#include <stdio.h>
#include <string.h>

int testing_assert_string_eq(char *str1, char *str2, char *name)
{
	int result;

	result = string_compare(str1, str2);
	if (result)
		fprintf(stdout, "%16s : %s\n", name, "pass");
	else
		fprintf(stdout, "%16s : %s\n", name, "fail");
	return (result == 0);
}
