/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_string_map_apply.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 16:15:34 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/02 16:15:35 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../build/plib_test.h"

static int test1(void)
{
	char *test1;

	test1 = string_clone("abcdefghijklmnopqrstuvwxyz");
	test1 = string_map_apply(test1, char_to_uppercase);
	if (string_compare(test1, "ABCDEFGHIJKLMNOPQRSTUVWXYZ") != 0)
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

	test1 = 0;
	test1 = string_map_apply(test1, char_to_uppercase);
	if (!test1)
		return (PASS);
	string_destroy(test1);
	return (FAIL);
}

static int test3(void)
{
	char *test1;

	test1 = string_clone("abcdefghijklmnopqrstuvwxyz");
	test1 = string_map_apply(test1, 0);
	if (!test1)
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

	test1 = string_clone("");
	test1 = string_map_apply(test1, char_to_uppercase);
	if (string_compare(test1, "") == 0)
	{
		string_destroy(test1);
		return (PASS);
	}
	string_destroy(test1);
	return (FAIL);
}

int test_string_map_apply(void)
{
	test_print_verbose_start((char *) __FUNCTION__);
	test_print_verbose_test("test1", test1() == PASS);
	test_print_verbose_test("test2", test2() == PASS);
	test_print_verbose_test("test3", test3() == PASS);
	test_print_verbose_test("test4", test4() == PASS);
	test_print_verbose_end();
	return (1);
}
