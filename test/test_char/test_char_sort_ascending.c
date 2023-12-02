/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_char_sort_ascending.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 10:50:15 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/02 10:50:17 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../build/plib_test.h"

int	test_char_sort_ascending(void)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (i < 256)
	{
		if (char_sort_ascending(i, i + 1))
			++count;
		++i;
	}
	test_print_verbose_start((char *) __FUNCTION__);
	test_print_verbose_test("test1", count == 256);
	test_print_verbose_end();
	return (count == 256);
}
