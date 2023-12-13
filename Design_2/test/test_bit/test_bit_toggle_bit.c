/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_bit_toggle_bit.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 21:46:42 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/05 21:47:14 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../build/plib_test.h"

static int test1(void)
{
	unsigned int test;

	test = 1;
	if (bit_toggle_bit(test, 0) == 0)
		return (PASS);
	return (FAIL);
}

static int test2(void)
{
	unsigned int test;

	test = 2;
	if (bit_toggle_bit(test, 0) == 3)
		return (PASS);
	return (FAIL);
}

static int test3(void)
{
	unsigned int test;

	test = 4;
	if (bit_toggle_bit(test, 1) == 6)
		return (PASS);
	return (FAIL);
}

static int test4(void)
{
	unsigned int test;

	test = 8;
	if (bit_toggle_bit(test, 6) == 72)
		return (PASS);
	return (FAIL);
}

static int test5(void)
{
	unsigned int test;

	test = 256;
	if (bit_toggle_bit(test, 1) == 258)
		return (PASS);
	return (FAIL);
}

int test_bit_toggle_bit(void)
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

