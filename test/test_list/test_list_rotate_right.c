/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_list_rotate_right.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:29:35 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/05 14:29:36 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../build/plib_test.h"

static int	test1(void)
{
	t_list	*list;
	char	*str1;
	char	*str2;
	char	*str3;

	str1 = "This ";
	str2 = "is ";
	str3 = "a test";
	list = list_create(str1);
	list_insert_back(&list, str2);
	list_insert_back(&list, str3);
	list_rotate_right(&list, 0);
	if (list_length(list) != 3)
	{
		list_destroy(list);
		return (FAIL);
	}
	if (string_compare(list_remove_front(&list), str1) != 0)
	{
		list_destroy(list);
		return (FAIL);
	}
	if (string_compare(list_remove_front(&list), str2) != 0)
	{
		list_destroy(list);
		return (FAIL);
	}
	if (string_compare(list_remove_front(&list), str3) != 0)
	{
		list_destroy(list);
		return (FAIL);
	}
	list_destroy(list);
	return (PASS);
}

static int	test2(void)
{
	t_list	*list;
	char	*str1;
	char	*str2;
	char	*str3;

	str1 = "This ";
	str2 = "is ";
	str3 = "a test";
	list = list_create(str1);
	list_insert_back(&list, str2);
	list_insert_back(&list, str3);
	list_rotate_right(&list, 1);
	if (list_length(list) != 3)
	{
		list_destroy(list);
		return (FAIL);
	}
	if (string_compare(list_remove_front(&list), str3) != 0)
	{
		list_destroy(list);
		return (FAIL);
	}
	if (string_compare(list_remove_front(&list), str1) != 0)
	{
		list_destroy(list);
		return (FAIL);
	}
	if (string_compare(list_remove_front(&list), str2) != 0)
	{
		list_destroy(list);
		return (FAIL);
	}
	list_destroy(list);
	return (PASS);
}

static int	test3(void)
{
	t_list	*list;
	char	*str1;
	char	*str2;
	char	*str3;

	str1 = "This ";
	str2 = "is ";
	str3 = "a test";
	list = list_create(str1);
	list_insert_back(&list, str2);
	list_insert_back(&list, str3);
	list_rotate_right(&list, 2);
	if (list_length(list) != 3)
	{
		list_destroy(list);
		return (FAIL);
	}
	if (string_compare(list_remove_front(&list), str2) != 0)
	{
		list_destroy(list);
		return (FAIL);
	}
	if (string_compare(list_remove_front(&list), str3) != 0)
	{
		list_destroy(list);
		return (FAIL);
	}
	if (string_compare(list_remove_front(&list), str1) != 0)
	{
		list_destroy(list);
		return (FAIL);
	}
	list_destroy(list);
	return (PASS);
}

static int	test4(void)
{
	t_list	*list;
	char	*str1;
	char	*str2;
	char	*str3;

	str1 = "This ";
	str2 = "is ";
	str3 = "a test";
	list = list_create(str1);
	list_insert_back(&list, str2);
	list_insert_back(&list, str3);
	list_rotate_right(&list, 9);
	if (list_length(list) != 3)
	{
		list_destroy(list);
		return (FAIL);
	}
	if (string_compare(list_remove_front(&list), str1) != 0)
	{
		list_destroy(list);
		return (FAIL);
	}
	if (string_compare(list_remove_front(&list), str2) != 0)
	{
		list_destroy(list);
		return (FAIL);
	}
	if (string_compare(list_remove_front(&list), str3) != 0)
	{
		list_destroy(list);
		return (FAIL);
	}
	list_destroy(list);
	return (PASS);
}

static int	test5(void)
{
	t_list	*list;

	list = 0;
	if (list_rotate_right(&list, 42) == 0)
		return (PASS);
	return (FAIL);
}

static int	test6(void)
{
	if (list_rotate_right(0, 42) == 0)
		return (PASS);
	return (FAIL);
}


int	test_list_rotate_right(void)
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

