/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_string_split_compare.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 18:12:38 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/03 18:44:34 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../build/plib_test.h"
#include <stdio.h>

static int test1(void)
{
	char  *test;
	char **test1;
	char **test2;

	test = "This is a test";
	test1 = string_split(test, ' ');
	test2 = string_split(test, ' ');
	if (string_split_compare(test1, test2) == 0)
	{
		string_split_destroy(test1, string_split_size(test1));
		string_split_destroy(test2, string_split_size(test2));
		return (PASS);
	}
	string_split_destroy(test1, string_split_size(test1));
	string_split_destroy(test2, string_split_size(test2));
	return (FAIL);
}


static int test2(void)
{
	char  *test;
	char **test1;
	char **test2;

	test = "This is a test";
	test1 = 0;
	test2 = string_split(test, ' ');
	if (string_split_compare(test1, test2) == 0)
	{
		string_split_destroy(test2, string_split_size(test2));
		return (PASS);
	}
	string_split_destroy(test2, string_split_size(test2));
	return (FAIL);
}


static int test3(void)
{
	char  *test;
	char **test1;
	char **test2;

	test = "This is a test";
	test1 = string_split(test, ' ');
	test2 = 0;
	if (string_split_compare(test1, test2) == 0)
	{
		string_split_destroy(test2, string_split_size(test2));
		return (PASS);
	}
	string_split_destroy(test2, string_split_size(test2));
	return (FAIL);
}

static int test4(void)
{
	char  *test01;
	char  *test0;
	char **test1;
	char **test2;

	test0 = "This is a test";
	test01 = "This is a tests";
	test1 = string_split(test0, ' ');
	test2 = string_split(test01, ' ');
	if (string_split_compare(test1, test2) != 0)
	{
		string_split_destroy(test1, string_split_size(test1));
		string_split_destroy(test2, string_split_size(test2));
		return (PASS);
	}
	string_split_destroy(test1, string_split_size(test1));
	string_split_destroy(test2, string_split_size(test2));
	return (FAIL);
}

int test_string_split_compare(void)
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
