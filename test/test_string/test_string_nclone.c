/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_string_nclone.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 16:16:54 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/02 16:16:55 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../build/plib_test.h"

static int	test1(void)
{
	char	*test1;
	char	*result;

	test1 = "This is a test";
	result = string_nclone(test1, string_length(test1));
	if (memory_compare(result, "This is a test", 14) == 0)
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
	char	*result;

	test1 = "";
	result = string_nclone(test1, 42);
	if (memory_compare(result, "", 1) == 0)
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

	test1 = 0;
	result = string_nclone(test1, 42);
	if (!result)
		return (PASS);
	return (FAIL);
}

static int	test4(void)
{
	char	*test1;
	char	*result;

	test1 = "This";
	result = string_nclone(test1, 1);
	if (memory_compare(result, "T", 1) == 0)
	{
		string_destroy(result);
		return (PASS);
	}
	string_destroy(result);
	return (FAIL);
}

int	test_string_nclone(void)
{
	test_print_verbose_start((char *)__FUNCTION__);
	test_print_verbose_test("test1", test1() == PASS);
	test_print_verbose_test("test2", test2() == PASS);
	test_print_verbose_test("test3", test3() == PASS);
	test_print_verbose_test("test4", test4() == PASS);
	test_print_verbose_end();
	return (1);
}
