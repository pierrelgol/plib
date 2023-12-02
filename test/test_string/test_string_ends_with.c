/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_string_ends_with.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 16:13:23 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/02 16:26:15 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../build/plib_test.h"

static int	test1(void)
{
	char	*test1;
	char	*test2;

	test1 = "This is a test";
	test2 = "This is a test";
	if (!string_ends_with(test1, test2))
		return (PASS);
	return (FAIL);
}


static int	test2(void)
{
	char	*test1;
	char	*test2;

	test1 = 0;
	test2 = "This is a test";
	if (!string_ends_with(test1, test2))
		return (PASS);
	return (FAIL);
}

static int	test3(void)
{
	char	*test1;
	char	*test2;

	test1 = "This is a test";
	test2 = 0;
	if (!string_ends_with(test1, test2))
		return (PASS);
	return (FAIL);
}

static int	test4(void)
{
	char	*test1;
	char	*test2;

	test1 = "This is a test";
	test2 = "This is a test that will fail because test2 can't even fit into test1";
	if (!string_ends_with(test1, test2))
		return (PASS);
	return (FAIL);
}

static int	test5(void)
{
	char	*test1;
	char	*test2;

	test1 = "est";
	test2 = "st";
	if (string_ends_with(test1, test2))
		return (PASS);
	return (FAIL);
}

static int	test6(void)
{
	char	*test1;
	char	*test2;

	test1 = "est";
	test2 = "zt";
	if (string_ends_with(test1, test2))
		return (FAIL);
	return (PASS);
}

static int	test7(void)
{
	char	*test1;
	char	*test2;

	test1 = "t";
	test2 = "";
	if (string_ends_with(test1, test2))
		return (FAIL);
	return (PASS);
}


int	test_string_ends_with(void)
{
	test_print_verbose_start((char *)__FUNCTION__);
	test_print_verbose_test("test1", test1() == PASS);
	test_print_verbose_test("test2", test2() == PASS);
	test_print_verbose_test("test3", test3() == PASS);
	test_print_verbose_test("test4", test4() == PASS);
	test_print_verbose_test("test5", test5() == PASS);
	test_print_verbose_test("test6", test6() == PASS);
	test_print_verbose_test("test7", test7() == PASS);
	test_print_verbose_end();
	return (1);
}

