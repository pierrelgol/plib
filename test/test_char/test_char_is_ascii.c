/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_char_is_ascii.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 10:48:20 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/02 10:48:21 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../build/plib_test.h"

int	test_char_is_ascii(void)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (i < 255)
	{
		if (char_is_ascii(i))
			++count;
		++i;
	}
	test_print_verbose_start((char *) __FUNCTION__);
	test_print_verbose_test("test1", count == 128);
	test_print_verbose_end();
	return (count == 128);
}
