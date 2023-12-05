/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_bit_count_set_bits.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 21:15:56 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/05 21:15:57 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../build/plib_test.h"

static int test1(void)
{
	unsigned int test;

	test = 0;
	if (bit_count_set_bits(test) == 0)
		return (PASS);
	return (FAIL);
}

static int test2(void)
{
	unsigned int test;

	test = 255;
	if (bit_count_set_bits(test) == 8)
		return (PASS);
	return (FAIL);
}

static int test3(void)
{
	unsigned int test;

	test = 127;
	if (bit_count_set_bits(test) == 7)
		return (PASS);
	return (FAIL);
}

static int test4(void)
{
	unsigned int test;

	test = 1;
	if (bit_count_set_bits(test) == 1)
		return (PASS);
	return (FAIL);
}

static int test5(void)
{
	unsigned int test;

	test = 2147483647;
	if (bit_count_set_bits(test) == 31)
		return (PASS);
	return (FAIL);
}

int test_bit_count_set_bits(void)
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
