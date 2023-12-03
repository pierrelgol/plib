/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_string_trim_right.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 18:42:31 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/03 18:42:31 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../build/plib_test.h"
#include <stdio.h>

static int test1(void)
{
	char *test;
	char *result;

	test = "00abcdef00";
	result = string_trim_right(test, '0');
	if (string_compare(result, "00abcdef") == 0)
	{
		string_destroy(result);
		return (PASS);
	}
	string_destroy(result);
	return (PASS);
}

static int test2(void)
{
	char *test;
	char *result;

	test = "";
	result = string_trim_right(test, '0');
	if (string_compare(result, "") != 0)
		return (FAIL);
	return (PASS);
}

static int test3(void)
{
	char *test;
	char *result;

	test = "abcdef";
	result = string_trim_right(test, '0');
	if (string_compare(result, "abcdef") == 0)
	{
		string_destroy(result);
		return (PASS);
	}
	string_destroy(result);
	return (PASS);
}

static int test4(void)
{
	char *test;
	char *result;

	test = 0;
	result = string_trim_right(test, '0');
	if (!result)
		return (PASS);
	string_destroy(result);
	return (FAIL);
}

static int test5(void)
{
	char *test;
	char *result;

	test = "010";
	result = string_trim_right(test, '0');
	if (string_compare(result, "01") == 0)
	{
		string_destroy(result);
		return (PASS);
	}
	printf("%s",result);
	string_destroy(result);
	return (FAIL);
}

int test_string_trim_right(void)
{
	test_print_verbose_start((char *) __FUNCTION__);
	test_print_verbose_test("test1", test1() == PASS);
	test_print_verbose_test("test2", test2() == PASS);
	test_print_verbose_test("test3", test3() == PASS);
	test_print_verbose_test("test4", test4() == PASS);
	test_print_verbose_test("test5", test5() == PASS);
	test_print_verbose_end();

	return (1);
}
