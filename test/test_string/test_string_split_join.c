/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_string_split_join.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 17:44:13 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/03 18:27:59 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../build/plib_test.h"
#include <stdio.h>

static int	test1(void)
{
	char	**test;
	char	*result;

	test = string_split("This is a test", ' ');
	result = string_split_join(test, ' ');
	if (string_compare(result, "This is a test") == 0)
	{
		string_destroy(result);
		string_split_destroy(test, string_split_size(test));
		return (PASS);
	}
	string_destroy(result);
	string_split_destroy(test, string_split_size(test));
	return (FAIL);
}

static int	test2(void)
{
	char	**test;
	char	*result;

	test = 0;
	result = string_split_join(test, ' ');
	if (!result)
		return (PASS);
	string_destroy(result);
	return (FAIL);
}

static int	test3(void)
{
	char	**test;
	char	*result;

	test = string_split("This", ' ');
	result = string_split_join(test, ' ');
	if (string_compare(result, "This") == 0)
	{
		string_destroy(result);
		string_split_destroy(test, string_split_size(test));
		return (PASS);
	}
	string_destroy(result);
	string_split_destroy(test, string_split_size(test));
	return (FAIL);
}

int	test_string_split_join(void)
{
	test_print_verbose_start((char *)__FUNCTION__);
	test_print_verbose_test("test1", test1() == PASS);
	test_print_verbose_test("test2", test2() == PASS);
	test_print_verbose_test("test3", test3() == PASS);
	test_print_verbose_end();
	return (1);
}
