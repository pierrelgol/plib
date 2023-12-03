/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_string_set_at.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 16:22:30 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/02 16:22:31 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../build/plib_test.h"

static int	test1(void)
{
	char	*test1;
	char	test2;

	test1 = string_clone("This is a test");
	test2 = string_set_at(test1,  -5, '0');
	if (test2 == -1)
	{
		string_destroy(test1);
		return (PASS);
	}
	string_destroy(test1);
	return (FAIL);
}


static int	test2(void)
{
	char	*test1;
	char	test2;

	test1 = "This is a test";
	test2 = string_set_at(test1,  1337, '0');
	if (test2 == -1)
		return (PASS);
	return (FAIL);
}

static int	test3(void)
{
	char	*test1;

	test1 = string_clone("This is a test");
	string_set_at(test1,  0, '0');
	if (string_compare(test1, "0his is a test") == 0)
	{
		string_destroy(test1);
		return (PASS);
	}
	string_destroy(test1);
	return (FAIL);
}

static int	test4(void)
{
	char	*test1;

	test1 = string_clone("This is a test");
	string_set_at(test1,  string_length(test1) - 1, '0');
	if (string_compare(test1, "This is a tes0") == 0)
	{
		string_destroy(test1);
		return (PASS);
	}
	string_destroy(test1);
	return (FAIL);
}


int	test_string_set_at(void)
{
	test_print_verbose_start((char *)__FUNCTION__);
	test_print_verbose_test("test1", test1() == PASS);
	test_print_verbose_test("test2", test2() == PASS);
	test_print_verbose_test("test3", test3() == PASS);
	test_print_verbose_test("test4", test4() == PASS);
	test_print_verbose_end();
	return (1);
}


