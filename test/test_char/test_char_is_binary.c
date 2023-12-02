/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_char_is_binary.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 10:48:27 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/02 10:48:28 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../build/plib_test.h"

int	test_char_is_binary(void)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (i < 127)
	{
		if (char_is_binary(i))
			++count;
		++i;
	}
	test_print_verbose_start((char *) __FUNCTION__);
	test_print_verbose_test("test1", count == 2);
	test_print_verbose_end();
	return (count == 2);
}
