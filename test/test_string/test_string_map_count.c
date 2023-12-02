/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_string_map_count.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 16:15:50 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/02 16:15:51 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../build/plib_test.h"

static int test1(void)
{
	if (string_map_count("abcdefghijklmnopqrstuvwxyz", char_is_lowercase) == 26)
		return (PASS);
	return (FAIL);
}

static int test2(void)
{
	if (!string_map_count(0,char_is_lowercase))
		return (PASS);
	return (FAIL);
}

static int test3(void)
{
	if (!string_map_count("abcdefghijklmnopqrstuvwxyz",0))
		return (PASS);
	return (FAIL);
}

static int test4(void)
{

	if (string_map_count("",char_is_lowercase) == 0)
		return (PASS);
	return (FAIL);
}

static int test5(void)
{
	if (string_map_count("abcdefghijklmnopqrstuvwxyz", char_is_uppercase) == 0)
		return (PASS);
	return (FAIL);
}

int test_string_map_count(void)
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

