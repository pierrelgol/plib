/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_string_clone.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 12:20:41 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/02 12:20:41 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../build/plib_test.h"

static int test1(void)
{
	char *test1;
	char *result;

	test1 = "This is a test";
	result = string_clone(test1);
	if (memory_compare(result, "This is a test", 14) == 0)
	{
		string_destroy(result);
		return (PASS);
	}
	string_destroy(result);
	return (FAIL);
}


static int test2(void)
{
	char *test1;
	char *result;

	test1 = "";
	result = string_clone(test1);
	if (memory_compare(result, "", 1) == 0)
	{
		string_destroy(result);
		return (PASS);
	}
	string_destroy(result);
	return (FAIL);
}


static int test3(void)
{
	char *test1;
	char *result;

	test1 = 0;
	result = string_clone(test1);
	if (!result)
		return (PASS);
	return (FAIL);
}

static int test4(void)
{
	char *result;

	result = string_clone((char*)0);
	if (!result)
		return (PASS);
	return (FAIL);
}

int test_string_clone(void)
{
	test_print_verbose_start((char *) __FUNCTION__);
	test_print_verbose_test("test1", test1() == PASS);
	test_print_verbose_test("test2", test2() == PASS);
	test_print_verbose_test("test3", test3() == PASS);
	test_print_verbose_test("test4", test4() == PASS);
	test_print_verbose_end();

	return (1);
}
