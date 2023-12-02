/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_string_map_slice.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 16:16:35 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/02 16:16:36 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../build/plib_test.h"

static int test1(void)
{
	char *test1;
	char *test2;

	test1 = "abcdefghijkl0123456789mnopqrstuvwxyz";
	test2 = string_map_slice(test1, char_is_digit);
	if (string_compare(test2, "0123456789") != 0)
	{
		string_destroy(test2);
		return (FAIL);
	}
	string_destroy(test2);
	return (PASS);
}

static int test2(void)
{
	char *test1;
	char *test2;

	test1 = "abcdefghijkl0mnopqrstuvwxyz";
	test2 = string_map_slice(test1, char_is_digit);
	if (string_compare(test2, "0") != 0)
	{
		string_destroy(test2);
		return (FAIL);
	}
	string_destroy(test2);
	return (PASS);
}

static int test3(void)
{
	char *test1;
	char *test2;

	test1 = "abcdefghijkl0mnopqrstuvwxyz";
	test2 = string_map_slice(test1, char_is_spaces);
	if (string_compare(test2, "") != 0)
	{
		string_destroy(test2);
		return (FAIL);
	}
	string_destroy(test2);
	return (PASS);
}


static int test4(void)
{
	char *test1;
	char *test2;

	test1 = "";
	test2 = string_map_slice(test1, char_is_spaces);
	if (string_compare(test2, "") != 0)
	{
		string_destroy(test2);
		return (FAIL);
	}
	string_destroy(test2);
	return (PASS);
}

static int test5(void)
{
	char *test1;
	char *test2;

	test1 = 0;
	test2 = string_map_slice(test1, char_is_spaces);
	if (!test2)
	{
		string_destroy(test2);
		return (PASS);
	}
	string_destroy(test2);
	return (FAIL);
}

static int test6(void)
{
	char *test1;
	char *test2;

	test1 = 0;
	test2 = string_map_slice(test1, 0);
	if (!test2)
	{
		string_destroy(test2);
		return (PASS);
	}
	string_destroy(test2);
	return (FAIL);
}


int test_string_map_slice(void)
{
	test_print_verbose_start((char *) __FUNCTION__);
	test_print_verbose_test("test1", test1() == PASS);
	test_print_verbose_test("test2", test2() == PASS);
	test_print_verbose_test("test3", test3() == PASS);
	test_print_verbose_test("test4", test4() == PASS);
	test_print_verbose_test("test5", test5() == PASS);
	test_print_verbose_test("test6", test6() == PASS);
	test_print_verbose_end();
	return (1);
}
