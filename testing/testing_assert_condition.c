/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing_assert_condition.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 21:05:03 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/06 21:05:04 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"
#include <stdio.h>

int testing_assert_condition(int condition, char *name)
{
	if (condition)
		fprintf(stdout, "%16s : %s\n", name, "pass");
	else
		fprintf(stdout, "%16s : %s\n", name,"fail");
	return (condition);
}
