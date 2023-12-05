/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_string_njoin.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 16:17:30 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/02 16:17:31 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../build/plib_test.h"

static int	test1(void)
{
	char	*test1;
	char	*test2;
	char	*result;

	test1 = "This";
	test2 = " is a test";
	result = string_njoin(test1, test2, 2);
	if (string_compare(result, "Th is a te") == 0)
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

	test1 = 0;
	test2 = " is a test";
	result = string_njoin(test1, test2, 1);
	if (!result)
		return (PASS);
	return (FAIL);
}

static int	test3(void)
{
	char	*test1;
	char	*test2;
	char	*result;

	test1 = "This";
	test2 = 0;
	result = string_njoin(test1, test2, 1);
	if (!result)
		return (PASS);
	return (FAIL);
}

static int	test4(void)
{
	char	*test1;
	char	*test2;
	char	*result;

	test1 = "";
	test2 = "";
	result = string_njoin(test1, test2, 0);
	if (string_compare(result, "") == 0)
	{
		string_destroy(result);
		return (PASS);
	}
	string_destroy(result);
	return (FAIL);
}

int	test_string_njoin(void)
{
	test_print_verbose_start((char *)__FUNCTION__);
	test_print_verbose_test("test1", test1() == PASS);
	test_print_verbose_test("test2", test2() == PASS);
	test_print_verbose_test("test3", test3() == PASS);
	test_print_verbose_test("test4", test4() == PASS);
	test_print_verbose_end();
	return (1);
}
