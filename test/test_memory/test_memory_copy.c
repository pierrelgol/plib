/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_memory_copy.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 14:11:47 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/02 14:11:49 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../build/plib_test.h"

static int	test1(void)
{
	char	*test;
	char	*dest;

	test = "This is a test";
	dest = string_create(16);
	memory_copy(dest, test, string_length(test));
	if (memory_compare(dest, test, string_length(test)) != 0)
	{
		string_destroy(dest);
		return (FAIL);
	}
	string_destroy(dest);
	return (PASS);
}

static int	test2(void)
{
	char	*test;
	char	*dest;

	test = "This is a test of a string who's too long";
	dest = string_create(16);
	memory_copy(dest, test, 16);
	if (memory_compare(dest, test, string_length(test)) == 0)
	{
		string_destroy(dest);
		return (FAIL);
	}
	string_destroy(dest);
	return (PASS);
}

static int	test3(void)
{
	char	*test;
	char	*dest;

	test = 0;
	dest = string_create(16);
	memory_copy(dest, test, string_length(test));
	if (memory_compare(dest, test, string_length(test)) == 0)
	{
		string_destroy(dest);
		return (PASS);
	}
	string_destroy(dest);
	return (FAIL);
}

static int	test4(void)
{
	char	*test;
	char	*dest;

	test = 0;
	dest = 0;
	memory_copy(dest, test, string_length(test));
	if (memory_compare(dest, test, string_length(test)) == 0)
	{
		string_destroy(dest);
		return (PASS);
	}
	string_destroy(dest);
	return (FAIL);
}

static int	test5(void)
{
	char	*test;
	char	*dest;

	test = "This is a test of a string who's too long";
	dest = string_create(16);
	memory_copy(dest, test, string_length(test));
	if (memory_compare(dest, test, 0) == 0)
	{
		string_destroy(dest);
		return (PASS);
	}
	string_destroy(dest);
	return (FAIL);
}

int	test_memory_copy(void)
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
