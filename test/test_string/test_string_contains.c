/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_string_contains.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 16:08:56 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/02 16:08:56 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../build/plib_test.h"

static int test1(void)
{
	char	*test1;
	char	*test2;

	test1 = 0;
	test2 = "This";
	if (!string_contains(test1, test2))
		return (PASS);
	return (FAIL);
}

static int test2(void)
{
	char	*test1;
	char	*test2;

	test1 = "This";
	test2 = 0;
	if (!string_contains(test1, test2))
		return (PASS);
	return (FAIL);
}


static int test3(void)
{
	char	*test1;
	char	*test2;

	test1 = "This is a test to see if it can find a very long string";
	test2 = "This is a test to see if it can find a very long string";
	if (!string_contains(test1, test2))
		return (FAIL);
	return (PASS);
}

static int test4(void)
{
	char	*test1;
	char	*test2;

	test1 = "This is still a test!";
	test2 = "test!";
	if (!string_contains(test1, test2))
		return (FAIL);
	return (PASS);
}

static int test5(void)
{
	char	*test1;
	char	*test2;

	test1 = "This is still a test!";
	test2 = "I'm not here";
	if (string_contains(test1, test2))
		return (FAIL);
	return (PASS);
}


int test_string_contains(void)
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
