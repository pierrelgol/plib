/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_string_map_assert.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 20:38:53 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/02 20:38:53 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../build/plib_test.h"

static int test1(void)
{
	char *test1;

	test1 = "abcdefghijklmnopqrstuvwxyz";
	if (!string_map_assert(test1, char_is_lowercase))
		return (FAIL);
	return (PASS);
}

static int test2(void)
{
	char *test1;

	test1 = "abcdefghijklmnopqrstuvwxyzZ";
	if (string_map_assert(test1, char_is_lowercase))
		return (FAIL);
	return (PASS);
}
static int test3(void)
{
	char *test1;

	test1 = 0;
	if (string_map_assert(test1, char_is_lowercase) != -1)
		return (FAIL);
	return (PASS);
}

static int test4(void)
{
	char *test1;

	test1 = "abcdefghijklmnopqrstuvwxyzZ";
	if (string_map_assert(test1, 0) != -1)
		return (FAIL);
	return (PASS);
}

int test_string_map_assert(void)
{
	test_print_verbose_start((char *) __FUNCTION__);
	test_print_verbose_test("test1", test1() == PASS);
	test_print_verbose_test("test2", test2() == PASS);
	test_print_verbose_test("test3", test3() == PASS);
	test_print_verbose_test("test4", test4() == PASS);
	test_print_verbose_end();
	return (1);
}
