/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_char_to_reversecase.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 11:52:35 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/02 11:52:39 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../build/plib_test.h"

int	test_char_to_reversecase(void)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (i < 128)
	{
		if (char_to_reversecase(asciiTable[i]) != i)
			++count;
		++i;
	}
	test_print_verbose_start((char *) __FUNCTION__);
	test_print_verbose_test("test1", count == 52);
	test_print_verbose_end();
	return (count == 52);
}
