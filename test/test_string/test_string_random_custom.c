/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_string_random_custom.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 16:20:15 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/02 16:20:16 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../build/plib_test.h"

static int test1(void)
{
	char *test;
	char *set;

	set = string_to_boolset("abcdefhijklmnopqrstuvwxyz", (char[255]){0});
	test = string_random_custom(set, 32);
	if (string_length(test) == 32)
	{
		string_destroy(test);
		return (PASS);
	}
	string_destroy(test);
	return (FAIL);
}

static int test2(void)
{
	char *test;
	char *set;

	set = string_to_boolset("abcdefhijklmnopqrstuvwxyz", (char[255]){0});
	test = string_random_custom(set, 32);
	if (string_map_assert(test, char_is_lowercase))
	{
		string_destroy(test);
		return (PASS);
	}
	string_destroy(test);
	return (FAIL);
}

static int test3(void)
{
	char *test;
	char *set;

	set = 0;
	test = string_random_custom(set, 32);
	if (!test)
		return (PASS);
	string_destroy(test);
	return (FAIL);
}
static int test4(void)
{
	char *test;
	char *set;

	set = string_to_boolset("a", (char[255]){0});
	test = string_random_custom(set, 0);
	if (!test)
		return (PASS);
	string_destroy(test);
	return (FAIL);
}

int test_string_random_custom(void)
{
	test_print_verbose_start((char *) __FUNCTION__);
	test_print_verbose_test("test1", test1() == PASS);
	test_print_verbose_test("test2", test2() == PASS);
	test_print_verbose_test("test3", test3() == PASS);
	test_print_verbose_test("test4", test4() == PASS);
	test_print_verbose_end();

	return (1);
}
