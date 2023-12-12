/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_memory_search.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 12:22:24 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/02 12:22:25 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../build/plib_test.h"

static int	test1(void)
{
	char	*test;
	char	*ptr;

	test = 0;
	ptr = 0;
	ptr = memory_search(test, 'T', 10);
	if (!ptr)
		return (PASS);
	return (FAIL);
}

static int	test2(void)
{
	char	*test;
	char	*ptr;

	test = "This is a test";
	ptr = 0;
	ptr = memory_search(test, 'T', 0);
	if (!ptr)
		return (PASS);
	return (FAIL);
}

static int	test3(void)
{
	char	*test;
	char	*ptr;

	test = "This is a test";
	ptr = 0;
	ptr = memory_search(test, 'z', string_length(test));
	if (!ptr)
		return (PASS);
	return (FAIL);
}

static int	test4(void)
{
	char	*test;
	char	*ptr;

	test = "This is a test";
	ptr = 0;
	ptr = memory_search(test, 'T', 10);
	if (!ptr)
		return (FAIL);
	if (*ptr == 'T')
		return (PASS);
	return (FAIL);
}

static int	test5(void)
{
	char	*test;
	char	*ptr;

	test = "This is a test a very long one!";
	ptr = 0;
	ptr = memory_search(test, '!', string_length(test));
	if (!ptr)
		return (FAIL);
	if (*ptr == '!')
		return (PASS);
	return (FAIL);
}

static int	test6(void)
{
	char	*test;
	char	*ptr;

	test = "This is a test a very long one!";
	ptr = 0;
	ptr = memory_search(test, '!', string_length(test) - 1);
	if (!ptr)
		return (PASS);
	if (*ptr == '!')
		return (FAIL);
	return (FAIL);
}

int	test_memory_search(void)
{
	test_print_verbose_start((char *)__FUNCTION__);
	test_print_verbose_test("test1", test1() == PASS);
	test_print_verbose_test("test2", test2() == PASS);
	test_print_verbose_test("test3", test3() == PASS);
	test_print_verbose_test("test4", test4() == PASS);
	test_print_verbose_test("test5", test5() == PASS);
	test_print_verbose_test("test6", test6() == PASS);
	test_print_verbose_end();
	return (1);
}
