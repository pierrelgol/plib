/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_string_fill.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 16:13:36 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/02 16:13:37 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../build/plib_test.h"

static int test1(void)
{
	char *test1;
	char *test2;

	test1 = "00000000000000000000000000000000000000000000000000000000000000"
	        "00";
	test2 = string_create(string_length(test1));
	test2 = string_fill(test2, '0');
	if (string_compare(test1, test2) != 0)
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

	test1 = 0;
	test1 = string_fill(test1, '0');
	if (!test1)
		return (PASS);
	return (FAIL);
}

static int test3(void)
{
	char *test1;

	test1 = (char [2]){0};
	test1 = string_fill(test1, '0');
	if (string_compare(test1, "") == 0)
		return (PASS);
	return (FAIL);
}

int test_string_fill(void)
{
	test_print_verbose_start((char *) __FUNCTION__);
	test_print_verbose_test("test1", test1() == PASS);
	test_print_verbose_test("test2", test2() == PASS);
	test_print_verbose_test("test3", test3() == PASS);
	test_print_verbose_end();
	return (1);
}
