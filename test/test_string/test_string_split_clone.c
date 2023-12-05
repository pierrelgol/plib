/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_string_split_clone.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 17:44:51 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/03 18:44:23 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../build/plib_test.h"

static int	test1(void)
{
	char	**test;
	char	**result;

	test = string_split("This is a test", ' ');
	result = string_split_clone(test);
	if (string_split_compare(test, result) == 0)
	{
		string_split_destroy(test, string_split_size(test));
		string_split_destroy(result, string_split_size(result));
		return (PASS);
	}
	string_split_destroy(test, string_split_size(test));
	string_split_destroy(result, string_split_size(result));
	return (FAIL);
}

static int	test2(void)
{
	char	**test;
	char	**result;

	test = string_split("", ' ');
	result = string_split_clone(test);
	if (string_split_compare(test, result) == 0)
	{
		string_split_destroy(test, string_split_size(test));
		string_split_destroy(result, string_split_size(result));
		return (PASS);
	}
	string_split_destroy(test, string_split_size(test));
	string_split_destroy(result, string_split_size(result));
	return (FAIL);
}

static int	test3(void)
{
	char	**test;
	char	**result;

	test = 0;
	result = string_split_clone(test);
	if (!result)
		return (PASS);
	string_split_destroy(result, string_split_size(result));
	return (FAIL);
}

int	test_string_split_clone(void)
{
	test_print_verbose_start((char *)__FUNCTION__);
	test_print_verbose_test("test1", test1() == PASS);
	test_print_verbose_test("test2", test2() == PASS);
	test_print_verbose_test("test3", test3() == PASS);
	// test_print_verbose_test("test4", test4() == PASS);
	// test_print_verbose_test("test5", test5() == PASS);
	test_print_verbose_end();
	return (1);
}
