/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_string_get_at.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 16:14:16 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/02 16:14:17 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../build/plib_test.h"

static int	test1(void)
{
	char	*test1;
	char	test2;

	test1 = "This is a test";
	test2 = string_get_at(test1,  -5);
	if (test2 == -1)
		return (PASS);
	return (FAIL);
}


static int	test2(void)
{
	char	*test1;
	char	test2;

	test1 = "This is a test";
	test2 = string_get_at(test1,  1337);
	if (test2 == -1)
		return (PASS);
	return (FAIL);
}

static int	test3(void)
{
	char	*test1;
	char	test2;

	test1 = "This is a test";
	test2 = string_get_at(test1,  0);
	if (test2 == 'T')
		return (PASS);
	return (FAIL);
}

static int	test4(void)
{
	char	*test1;
	char	test2;

	test1 = "This is a test";
	test2 = string_get_at(test1,  string_length(test1) - 1);
	if (test2 == 't')
		return (PASS);
	return (FAIL);
}

static int	test5(void)
{
	char	*test1;
	char	test2;

	test1 = 0;
	test2 = string_get_at(test1,  0);
	if (test2 == -1)
		return (PASS);
	return (FAIL);
}

int	test_string_get_at(void)
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

