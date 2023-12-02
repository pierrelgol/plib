/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_memory_clone.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 12:22:15 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/02 12:22:16 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../build/plib_test.h"

static int	test1(void)
{
	char	*test;
	char	*result;

	test = "This is a test";
	result = 0;
	result = memory_clone(test, string_length(test));
	if (!result)
		return (FAIL);
	if (memory_compare(test, result, string_length(test)) != 0)
	{
		memory_dealloc(result);
		return (FAIL);
	}
	memory_dealloc(result);
	return (PASS);
}

static int	test2(void)
{
	char	*test;
	char	*result;

	test = "This is a test";
	result = 0;
	result = memory_clone(test, 4);
	if (!result)
		return (FAIL);
	if (memory_compare(test, result, 4) != 0)
	{
		memory_dealloc(result);
		return (FAIL);
	}
	memory_dealloc(result);
	return (PASS);
}

static int	test3(void)
{
	char	*test;
	char	*result;

	test = 0;
	result = 0;
	result = memory_clone(test, 4);
	if (!result)
		return (PASS);
	memory_dealloc(result);
	return (FAIL);
}

static int	test4(void)
{
	char	*test;
	char	*result;

	test = "this is a test";
	result = 0;
	result = memory_clone(test, 0);
	if (!result)
		return (PASS);
	memory_dealloc(result);
	return (FAIL);
}

static int	test5(void)
{
	char	*test;
	char	*result;

	test = "";
	result = 0;
	result = memory_clone(test, 1);
	if (!result)
		return (FAIL);
	if (memory_compare(test, result, 1) != 0)
	{
		memory_dealloc(result);
		return (FAIL);
	}
	memory_dealloc(result);
	return (PASS);
}

int	test_memory_clone(void)
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
