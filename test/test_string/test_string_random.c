/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_string_random.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 16:19:11 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/02 16:19:11 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../build/plib_test.h"

static int	test1(void)
{
	char	*test;

	test = string_random(32);
	if (string_length(test) == 32)
	{
		string_destroy(test);
		return (PASS);
	}
	return (FAIL);
}

static int	test2(void)
{
	char	*test;

	test = string_random(0);
	if (!test)
		return (PASS);
	return (FAIL);
}

int	test_string_random(void)
{
	test_print_verbose_start((char *)__FUNCTION__);
	test_print_verbose_test("test1", test1() == PASS);
	test_print_verbose_test("test2", test2() == PASS);
	test_print_verbose_end();
	return (1);
}
