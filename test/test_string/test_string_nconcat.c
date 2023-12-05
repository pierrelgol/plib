/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_string_nconcat.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 16:17:12 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/02 16:17:12 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../build/plib_test.h"

static int	test1(void)
{
	char	*test1;
	char	*test2;

	test1 = "This";
	test2 = string_create(string_length(test1));
	string_nconcat(test2, test1, string_length(test1));
	if (string_compare(test1, test2) != 0)
	{
		string_destroy(test2);
		return (FAIL);
	}
	string_destroy(test2);
	return (PASS);
}

static int	test2(void)
{
	char	*test1;
	char	*test2;

	test1 = "This";
	test2 = string_create(string_length("This is a test"));
	string_nconcat(test2, test1, string_length("This is a test"));
	string_nconcat(test2, " is a test", string_length("This is a test"));
	if (string_compare(test2, "This is a test") != 0)
	{
		string_destroy(test2);
		return (FAIL);
	}
	string_destroy(test2);
	return (PASS);
}

static int	test3(void)
{
	char	*test1;
	char	*test2;

	test1 = 0;
	test2 = string_create(string_length("This is a test"));
	if (string_nconcat(test2, test1, 42) != 0)
	{
		string_destroy(test2);
		return (FAIL);
	}
	string_destroy(test2);
	return (PASS);
}

static int	test4(void)
{
	char	*test1;
	char	*test2;

	test1 = "This is a test";
	test2 = 0;
	if (string_nconcat(test2, test1, 42) != 0)
		return (FAIL);
	return (PASS);
}

static int	test5(void)
{
	char	*test1;
	char	*test2;

	test1 = "This is a test";
	test2 = "This is a test";
	if (string_nconcat(test2, test1, 0) != 0)
		return (FAIL);
	return (PASS);
}

int	test_string_nconcat(void)
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
