/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_string_create.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 16:09:22 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/02 16:09:23 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../build/plib_test.h"

static int test1(void)
{
	char	*test1;

	test1 = string_create(0);
	if (!test1)
		return (PASS);
	string_destroy(test1);
	return (FAIL);
}

static int test2(void)
{
	char	*test1;

	test1 = string_create(42);
	if (!test1)
		return (FAIL);
	string_destroy(test1);
	return (PASS);
}

static int test3(void)
{
	char	*test1;

	test1 = string_create(2147483647);
	if (!test1)
		return (PASS);
	string_destroy(test1);
	return (FAIL);
}

int test_string_create(void)
{
	test_print_verbose_start((char *) __FUNCTION__);
	test_print_verbose_test("test1", test1() == PASS);
	test_print_verbose_test("test2", test2() == PASS);
	test_print_verbose_test("test3", test3() == PASS);
	test_print_verbose_end();

	return (1);
}

