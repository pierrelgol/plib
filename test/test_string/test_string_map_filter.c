/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_string_map_filter.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 16:15:59 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/02 16:16:00 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../build/plib_test.h"

static int test1(void)
{
	char *test1;

	test1 = string_map_filter("abcdefghijklmnopqrstuvwxyz",char_is_lowercase);
	if (string_compare(test1, "") != 0)
	{
		string_destroy(test1);
		return (FAIL);
	}
	string_destroy(test1);
	return (PASS);
}

static int test2(void)
{
	char *test1;

	test1 = string_map_filter("00abcdefghijklmn00opqrstuvwxyz00",char_is_digit);
	if (string_compare(test1, "abcdefghijklmnopqrstuvwxyz") != 0)
	{
		string_destroy(test1);
		return (FAIL);
	}
	string_destroy(test1);
	return (PASS);
}

static int test3(void)
{
	char *test1;

	test1 = string_map_filter(0,char_is_digit);
	if (!test1)
		return (PASS);
	string_destroy(test1);
	return (FAIL);
}

static int test4(void)
{
	char *test1;

	test1 = string_map_filter("char_is_digit",0);
	if (!test1)
		return (PASS);
	string_destroy(test1);
	return (FAIL);
}

int test_string_map_filter(void)
{
	test_print_verbose_start((char *) __FUNCTION__);
	test_print_verbose_test("test1", test1() == PASS);
	test_print_verbose_test("test2", test2() == PASS);
	test_print_verbose_test("test3", test3() == PASS);
	test_print_verbose_test("test4", test4() == PASS);
	test_print_verbose_end();
	return (1);
}

