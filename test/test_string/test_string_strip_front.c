/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_string_strip_front.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 16:20:47 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/02 16:20:48 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../build/plib_test.h"

static int	test1(void)
{
	char	*test1;
	char	*test2;
	char	*result;

	test1 = "This is a test";
	test2 = "This";
	result = string_strip_front(test1, test2);
	if (string_compare(result, " is a test") == 0)
	{
		string_destroy(result);
		return (PASS);
	}
	string_destroy(result);
	return (FAIL);
}

static int	test2(void)
{
	char	*test1;
	char	*test2;
	char	*result;

	test1 = "This is a test";
	test2 = "This is a tes";
	result = string_strip_front(test1, test2);
	if (string_compare(result, "t") == 0)
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
	char	*test2;
	char	*result;

	test1 = "This is a test";
	test2 = "not here";
	result = string_strip_front(test1, test2);
	if (string_compare(result, "This is a test") == 0)
		return (PASS);
	return (FAIL);
}

static int	test4(void)
{
	char	*test1;
	char	*test2;
	char	*result;

	test1 = 0;
	test2 = "";
	result = string_strip_front(test1, test2);
	if (!result)
		return (PASS);
	return (FAIL);
}

static int	test5(void)
{
	char	*test1;
	char	*test2;
	char	*result;

	test1 = "";
	test2 = 0;
	result = string_strip_front(test1, test2);
	if (!result)
		return (PASS);
	return (FAIL);
}

int	test_string_strip_front(void)
{
	test_print_verbose_start((char *)__FUNCTION__);
	test_print_verbose_test("test1", test1() == PASS);
	test_print_verbose_test("test2", test2() == PASS);
	test_print_verbose_test("test3", test3() == PASS);
	test_print_verbose_test("test4", test4() == PASS);
	test_print_verbose_test("test5", test5() == PASS);
	test_print_verbose_end();
	return (1);
}
