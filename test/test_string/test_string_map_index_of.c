/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_string_map_index_of.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 16:16:15 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/02 16:16:15 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../build/plib_test.h"

static int test1(void)
{
	if (string_map_index_of("0123456789abcdef", char_is_lowercase) != 10)
		return (FAIL);
	return (PASS);
}

static int test2(void)
{
	if (string_map_index_of("0123456789abcdef", char_is_digit) != 0)
		return (FAIL);
	return (PASS);
}

static int test3(void)
{
	if (string_map_index_of("", char_is_digit) != -1)
		return (FAIL);
	return (PASS);
}

static int test4(void)
{
	if (string_map_index_of("0123456789abcdef", char_is_uppercase) != -1)
		return (FAIL);
	return (PASS);
}

static int test5(void)
{
	if (string_map_index_of(0, char_is_uppercase) != -1)
		return (FAIL);
	return (PASS);
}

static int test6(void)
{
	if (string_map_index_of(0, 0) != -1)
		return (FAIL);
	return (PASS);
}

int test_string_map_index_of(void)
{
	test_print_verbose_start((char *) __FUNCTION__);
	test_print_verbose_test("test1", test1() == PASS);
	test_print_verbose_test("test2", test2() == PASS);
	test_print_verbose_test("test3", test3() == PASS);
	test_print_verbose_test("test4", test4() == PASS);
	test_print_verbose_test("test5", test5() == PASS);
	test_print_verbose_test("test6", test6() == PASS);
	test_print_verbose_end();
	return (1);
}
