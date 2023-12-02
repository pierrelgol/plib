/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_string_search.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 16:21:46 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/02 16:21:48 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../build/plib_test.h"

static int test1(void)
{
	char	*test1;
	char	*test2;
	char	*result;

	test1 = 0;
	test2 = "This";
	result = string_search(test1, test2);
	if (!result)
		return (PASS);
	return (FAIL);
}

static int test2(void)
{
	char	*test1;
	char	*test2;
	char	*result;

	test1 = "This";
	test2 = 0;
	result = string_search(test1, test2);
	if (!result)
		return (PASS);
	return (FAIL);
}


static int test3(void)
{
	char	*test1;
	char	*test2;
	char	*result;

	test1 = "This is a test to see if it can find a very long string";
	test2 = "This is a test to see if it can find a very long string";
	result = string_search(test1, test2);
	if (!result)
		return (FAIL);
	if (string_compare(test1, result) != 0)
		return (FAIL);
	if (string_compare(test2, result) != 0)
		return (FAIL);
	return (PASS);
}

static int test4(void)
{
	char	*test1;
	char	*test2;
	char	*result;

	test1 = "This is still a test!";
	test2 = "test!";
	result = string_search(test1, test2);
	if (!result)
		return (FAIL);
	if (string_compare(test2, result) != 0)
		return (FAIL);
	return (PASS);
}



static int test5(void)
{
	char	*test1;
	char	*test2;
	char	*result;

	test1 = "This is still a test!";
	test2 = "I'm not here";
	result = string_search(test1, test2);
	if (!result)
		return (PASS);
	return (FAIL);
}


int test_string_search(void)
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
