/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_char_is_newline.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 10:46:19 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/02 10:46:20 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../build/plib_test.h"

int	test_char_is_newline(void)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (i < 256)
	{
		if (char_is_newline(i))
			++count;
		++i;
	}
	test_print_verbose_start((char *) __FUNCTION__);
	test_print_verbose_test("test1", count == 1);
	test_print_verbose_end();
	return (count == 1);
}
