/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_string_map_search.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 16:16:25 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/02 16:16:26 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../build/plib_test.h"

static int test1(void)
{
	char *test1;
	char *test2;

	test1 = "abcdefghijkl mnopqrstuvwxyz";
	test2 = string_map_search(test1, char_is_whitespace);
	if (string_compare(test2, " mnopqrstuvwxyz") != 0)
		return (FAIL);
	return (PASS);
}

static int test2(void)
{
	char *test1;
	char *test2;

	test1 = "abcdefghijkl mnopqrstuvwxyz";
	test2 = string_map_search(test1, char_is_uppercase);
	if (!test2)
		return (PASS);
	return (FAIL);
}
static int test3(void)
{
	char *test1;

	test1 = string_map_search("abcdefghijkl mnopqrstuvwxyz", 0);
	if (!test1)
		return (PASS);
	return (FAIL);
}

static int test4(void)
{
	char *test1;

	test1 = string_map_search(0, char_is_uppercase);
	if (!test1)
		return (PASS);
	return (FAIL);
}


int test_string_map_search(void)
{
	test_print_verbose_start((char *) __FUNCTION__);
	test_print_verbose_test("test1", test1() == PASS);
	test_print_verbose_test("test2", test2() == PASS);
	test_print_verbose_test("test3", test3() == PASS);
	test_print_verbose_test("test4", test4() == PASS);
	test_print_verbose_end();
	return (1);
}
