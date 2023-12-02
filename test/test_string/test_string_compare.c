/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_string_compare.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 12:21:17 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/02 12:21:19 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../build/plib_test.h"

static int test1(void)
{
	char	*test1;
	char	*test2;

	test1 = "";
	test2 = "";
	if (string_compare(test1, test2) != 0)
		return (FAIL);
	return (PASS);
}

static int test2(void)
{
	char	*test1;
	char	*test2;

	test1 = 0;
	test2 = "";
	if (string_compare(test1, test2) != 0)
		return (FAIL);
	return (PASS);
}

static int test3(void)
{
	char	*test1;
	char	*test2;

	test1 = 0;
	test2 = 0;
	if (string_compare(test1, test2) != 0)
		return (FAIL);
	return (PASS);
}

static int test4(void)
{
	char	*test1;
	char	*test2;

	test1 = "This is almost the same string";
	test2 = "This is almost the same strings";
	if (string_compare(test1, test2) >= 0)
		return (FAIL);
	return (PASS);
}


static int test5(void)
{
	char	*test1;
	char	*test2;

	test1 = "This is almost the same strings";
	test2 = "This is almost the same string";
	if (string_compare(test1, test2) <= 0)
		return (FAIL);
	return (PASS);
}

static int test6(void)
{
	char	*test1;
	char	*test2;

	test1 = "This is the same string";
	test2 = "This is the same string";
	if (string_compare(test1, test2) != 0)
		return (FAIL);
	return (PASS);
}


int test_string_compare(void)
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

