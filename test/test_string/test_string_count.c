/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_string_count.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 16:09:13 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/02 16:09:14 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../build/plib_test.h"

static int test1(void)
{
	char	*test1;

	test1 = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
	if (string_count(test1, 'a') != 64)
		return (FAIL);
	return (PASS);
}

static int test2(void)
{
	char	*test1;

	test1 = "";
	if (string_count(test1, 'a') != 0)
		return (FAIL);
	return (PASS);
}


static int test3(void)
{
	char	*test1;

	test1 = 0;
	if (string_count(test1, 'a') != 0)
		return (FAIL);
	return (PASS);
}

static int test4(void)
{
	char	*test1;

	test1 = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaz";
	if (string_count(test1, 'z') != 1)
		return (FAIL);
	return (PASS);
}

static int test5(void)
{
	char	*test1;

	test1 = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
	if (string_count(test1, 'y') != 0)
		return (FAIL);
	return (PASS);
}

int test_string_count(void)
{
	test_print_verbose_start((char *) __FUNCTION__);
	test_print_verbose_test("test1", test1() == PASS);
	test_print_verbose_test("test2", test2() == PASS);
	test_print_verbose_test("test3", test3() == PASS);
	test_print_verbose_test("test4", test4() == PASS);
	test_print_verbose_test("test5", test5() == PASS);
	test_print_verbose_end();

	return (1);
}
