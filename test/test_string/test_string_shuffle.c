/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_string_shuffle.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 16:22:40 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/02 16:22:42 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../build/plib_test.h"

static int test1(void)
{
	char *test1;

	test1 = 0;
	if (!string_shuffle(test1))
		return (PASS);
	return (FAIL);
}

static int test2(void)
{
	char *test1;
	char *result;

	test1 = string_clone("This is a test");
	result = string_shuffle(test1);
	if (string_compare(result, "This is a test") == 0)
	{
		string_destroy(result);
		return (FAIL);
	}
	string_destroy(result);
	return (PASS);
}

static int test3(void)
{
	char *test1;
	char *result;

	test1 = string_clone("Th");
	result = string_shuffle(test1);
	if (string_compare(result, "Th") == 0)
	{
		string_destroy(result);
		return (PASS);
	}
	string_destroy(result);
	return (PASS);
}

static int test4(void)
{
	char *test1;
	char *result;

	test1 = string_clone("T");
	result = string_shuffle(test1);
	if (string_compare(result, "T") == 0)
	{
		string_destroy(result);
		return (PASS);
	}
	string_destroy(result);
	return (FAIL);
}

int test_string_shuffle(void)
{
	test_print_verbose_start((char *) __FUNCTION__);
	test_print_verbose_test("test1", test1() == PASS);
	test_print_verbose_test("test2", test2() == PASS);
	test_print_verbose_test("test3", test3() == PASS);
	test_print_verbose_test("test4", test4() == PASS);
	test_print_verbose_end();
	return (1);
}
