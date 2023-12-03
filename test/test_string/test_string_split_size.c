/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_string_split_size.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 17:44:36 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/03 17:44:36 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../build/plib_test.h"
#include <stdio.h>

static int test1(void)
{
	char **result;

	result = string_split("", ' ');
	if (string_split_size(result) == 0)
	{
		string_split_destroy(result, string_split_size(result));
		return (PASS);
	}
	string_split_destroy(result, string_split_size(result));
	return (FAIL);
}

static int test2(void)
{
	char **result;

	result = string_split("This is a string", ' ');
	if (string_split_size(result) == 4)
	{
		string_split_destroy(result, string_split_size(result));
		return (PASS);
	}
	string_split_destroy(result, string_split_size(result));
	return (FAIL);
}

static int test3(void)
{
	char **result;

	result = 0;
	if (!string_split_size(result))
		return (PASS);
	return (FAIL);
}

int test_string_split_size(void)
{
	test_print_verbose_start((char *) __FUNCTION__);
	test_print_verbose_test("test1", test1() == PASS);
	test_print_verbose_test("test2", test2() == PASS);
	test_print_verbose_test("test3", test3() == PASS);
	test_print_verbose_end();
	return (1);
}
