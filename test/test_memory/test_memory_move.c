/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_memory_move.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 12:22:34 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/02 12:22:35 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../build/plib_test.h"
#include <stdio.h>

static int	test1(void)
{
	char	*ptr1;
	char	*ptr2;

	ptr1 = 0;
	ptr2 = "This";
	if (!memory_move(ptr1, ptr2, 5))
		return (PASS);
	return (FAIL);
}

static int	test2(void)
{
	char	*ptr1;
	char	*ptr2;

	ptr1 = "This";
	ptr2 = 0;
	if (!memory_move(ptr1, ptr2, 5))
		return (PASS);
	return (FAIL);
}

static int	test3(void)
{
	char	*ptr1;
	char	*ptr2;

	ptr1 = "This";
	ptr2 = "";
	if (ptr1 == memory_move(ptr1, ptr2, 0))
		return (PASS);
	return (FAIL);
}

static int	test4(void)
{
	char	*ptr1;
	char	*ptr2;

	ptr1 = string_create(33);
	string_copy(ptr1, "aabbccddeeffhhiijjkkll");
	ptr2 = (ptr1 + 2);
	memory_move(ptr1, ptr2, 2);
	if (string_compare(ptr1, "bbbbccddeeffhhiijjkkll") == 0)
	{
		string_destroy(ptr1);
		return (PASS);
	}
	string_destroy(ptr1);
	return (FAIL);
}

static int	test5(void)
{
	char	*ptr1;
	char	*ptr2;

	ptr1 = string_create(33);
	string_copy(ptr1, "aabbccddeeffhhiijjkkll");
	ptr2 = (ptr1);
	memory_move(ptr1 + 2, ptr2, 2);
	if (string_compare(ptr1, "aaaaccddeeffhhiijjkkll") == 0)
	{
		string_destroy(ptr1);
		return (PASS);
	}
	string_destroy(ptr1);
	return (FAIL);
}

static int	test6(void)
{
	char	*ptr1;
	char	*ptr2;

	ptr1 = string_create(33);
	string_copy(ptr1, "aabbccddeeffhhiijjkkll");
	ptr2 = (ptr1);
	memory_move(ptr1 + 2, ptr2, 0);
	if (string_compare(ptr1, "aabbccddeeffhhiijjkkll") == 0)
	{
		string_destroy(ptr1);
		return (PASS);
	}
	string_destroy(ptr1);
	return (FAIL);
}

int	test_memory_move(void)
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
