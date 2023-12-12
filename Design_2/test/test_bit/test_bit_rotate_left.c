/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_bit_rotate_left.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 21:32:02 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/05 21:32:22 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../build/plib_test.h"

static int test1(void)
{
	unsigned int test;

	test = 1;
	if (bit_rotate_left(test, 1) == 2)
		return (PASS);
	return (FAIL);
}

static int test2(void)
{
	unsigned int test;

	test = 2;
	if (bit_rotate_left(test, 1) == 4)
		return (PASS);
	return (FAIL);
}

static int test3(void)
{
	unsigned int test;

	test = 4;
	if (bit_rotate_left(test, 1) == 8)
		return (PASS);
	return (FAIL);
}

static int test4(void)
{
	unsigned int test;

	test = 8;
	if (bit_rotate_left(test, 1) == 16)
		return (PASS);
	return (FAIL);
}

static int test5(void)
{
	unsigned int test;

	test = 2147483647;
	if (bit_rotate_left(test, 1) == 4294967294)
		return (PASS);
	return (FAIL);
}

int test_bit_rotate_left(void)
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
