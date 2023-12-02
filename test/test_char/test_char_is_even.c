/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_char_is_even.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 10:47:29 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/02 10:47:57 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../build/plib_test.h"

int	test_char_is_even(void)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (i < 256)
	{
		if (char_is_even(i))
			++count;
		++i;
	}
	test_print_verbose_start((char *) __FUNCTION__);
	test_print_verbose_test("test1", count == 128);
	test_print_verbose_end();
	return (count == 128);
}
