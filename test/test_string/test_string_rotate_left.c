/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_string_rotate_left.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 16:21:08 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/02 16:21:08 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../build/plib_test.h"

static int test1(void)
{
	char *test1;
	char *result;

	test1 = 0;
	result = string_rotate_left(test1, 10);
	if (!result)
		return (PASS);
	return (FAIL);
}

static int test2(void)
{
	char *test1;
	char *result;

	test1 = string_clone("abcdef");
	result = string_rotate_left(test1, 1);
	if (string_compare(result, "bcdefa") == 0)
	{
		string_destroy(test1);
		return (PASS);
	}
	string_destroy(test1);
	return (FAIL);
}

static int test3(void)
{
	char *test1;
	char *result;

	test1 = string_clone("a");
	result = string_rotate_left(test1, 1);
	if (string_compare(result, "a") == 0)
	{
		string_destroy(test1);
		return (PASS);
	}
	string_destroy(test1);
	return (FAIL);
}

static int test4(void)
{
	char *test1;
	char *result;

	test1 = string_clone("ab");
	result = string_rotate_left(test1, 1);
	if (string_compare(result, "ba") == 0)
	{
		string_destroy(test1);
		return (PASS);
	}
	string_destroy(test1);
	return (FAIL);
}

static int test5(void)
{
	char *test1;
	char *result;

	test1 = string_clone("");
	result = string_rotate_left(test1, 42);
	if (string_compare(result, "") == 0)
	{
		string_destroy(test1);
		return (PASS);
	}
	string_destroy(test1);
	return (FAIL);
}

static int test6(void)
{
	char *test1;
	char *result;

	test1 = string_clone("abc");
	result = string_rotate_left(test1, 1);
	if (string_compare(result, "bca") == 0)
	{
		string_destroy(test1);
		return (PASS);
	}
	string_destroy(test1);
	return (FAIL);
}


int test_string_rotate_left(void)
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
