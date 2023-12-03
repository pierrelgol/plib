/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_string_split.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 16:23:15 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/02 16:23:15 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../build/plib_test.h"
#include <stdio.h>

static int test1(void)
{
	char  *test1;
	char **result;

	test1 = "This is a test";
	result = string_split(test1, ' ');
	if (string_compare(result[0], "This") == 0 && string_compare(result[1], "is") == 0 && string_compare(result[2], "a") == 0 && string_compare(result[3], "test") == 0)
	{
		string_split_destroy(result, string_split_size(result));
		return (PASS);
	}
	string_split_destroy(result, string_split_size(result));
	return (FAIL);
}

static int test2(void)
{
	char  *test1;
	char **result;

	test1 = "";
	result = string_split(test1, ' ');
	if (string_compare(result[0], "") == 0)
	{
		string_split_destroy(result, string_split_size(result));
		return (PASS);
	}
	string_split_destroy(result, string_split_size(result));
	return (FAIL);
}

static int test3(void)
{
	char  *test1;
	char **result;

	test1 = "This is a very long string";
	result = string_split(test1, 'z');
	if (string_compare(result[0], "This is a very long string") == 0)
	{
		string_split_destroy(result, string_split_size(result));
		return (PASS);
	}
	string_split_destroy(result, string_split_size(result));
	return (FAIL);
}

static int test4(void)
{
	char  *test1;
	char **result;

	test1 = 0;
	result = string_split(test1, 'z');
	if (!result)
		return (PASS);
	string_split_destroy(result, string_split_size(result));
	return (FAIL);
}



int test_string_split(void)
{
	test_print_verbose_start((char *) __FUNCTION__);
	test_print_verbose_test("test1", test1() == PASS);
	test_print_verbose_test("test2", test2() == PASS);
	test_print_verbose_test("test3", test3() == PASS);
	test_print_verbose_test("test4", test4() == PASS);
	// test_print_verbose_test("test5", test5() == PASS);
	test_print_verbose_end();
	return (1);
}
