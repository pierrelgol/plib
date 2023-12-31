/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_string_sort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 16:23:04 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/02 16:23:05 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../build/plib_test.h"
#include <stdio.h>

static int	test1(void)
{
	char	*test1;
	char	*result;

	test1 = "0123456789";
	result = string_sort(test1, char_sort_ascending);
	if (string_compare(result, "0123456789") == 0)
		return (PASS);
	return (FAIL);
}

static int	test2(void)
{
	char	*test1;
	char	*result;

	test1 = string_clone("0123456789");
	result = string_sort(test1, char_sort_descending);
	if (string_compare(result, string_reverse(test1)) == 0)
	{
		string_destroy(result);
		return (PASS);
	}
	string_destroy(result);
	return (FAIL);
}

static int	test3(void)
{
	char	*test1;
	char	*result;

	test1 = string_clone("0");
	result = string_sort(test1, char_sort_descending);
	if (string_compare(result, "0") == 0)
	{
		string_destroy(result);
		return (PASS);
	}
	string_destroy(result);
	return (FAIL);
}

static int	test4(void)
{
	char	*test1;
	char	*result;

	test1 = 0;
	result = string_sort(test1, char_sort_descending);
	if (!result)
		return (PASS);
	return (FAIL);
}

static int	test5(void)
{
	char	*test1;
	char	*result;

	test1 = string_clone("0");
	result = string_sort(test1, 0);
	if (string_compare(result, "0") == 0)
	{
		string_destroy(result);
		return (PASS);
	}
	string_destroy(result);
	return (FAIL);
}

static int	test6(void)
{
	char	*test1;
	char	*result;

	test1 = string_clone("01");
	result = string_sort(test1, char_sort_descending);
	if (string_compare(result, string_reverse(test1)) == 0)
	{
		string_destroy(result);
		return (PASS);
	}
	string_destroy(result);
	return (FAIL);
}

int	test_string_sort(void)
{
	test_print_verbose_start((char *)__FUNCTION__);
	test_print_verbose_test("test1", test1() == PASS);
	test_print_verbose_test("test2", test2() == PASS);
	test_print_verbose_test("test3", test3() == PASS);
	test_print_verbose_test("test4", test4() == PASS);
	test_print_verbose_test("test5", test5() == PASS);
	test_print_verbose_test("test6", test6() == PASS);
	test_print_verbose_end();
	return (1);
}
