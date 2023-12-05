/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_list_remove_back.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 10:11:18 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/05 10:11:21 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../build/plib_test.h"

static int	test1(void)
{
	t_list	*list;
	char	*str1;
	char	*str2;

	str1 = "This";
	str2 = "is a test";
	list = list_create(str1);
	list_insert_at(&list, str2, 1);
	if (list_length(list) != 2)
	{
		list_destroy(list);
		return (FAIL);
	}
	if (string_compare(list_remove_back(&list), "is a test") != 0)
	{
		list_destroy(list);
		return (FAIL);
	}
	if (string_compare(list_remove_back(&list), "This") != 0)
	{
		list_destroy(list);
		return (FAIL);
	}
	return (PASS);
}

static int	test2(void)
{
	t_list	*list;
	char	*str1;
	char	*str2;

	str1 = "This";
	str2 = "is a test";
	list = list_create(str1);
	list_insert_at(&list, str2, 0);
	if (list_length(list) != 2)
	{
		list_destroy(list);
		return (FAIL);
	}
	if (string_compare(list_remove_back(&list), "This") != 0)
	{
		list_destroy(list);
		return (FAIL);
	}
	if (string_compare(list_remove_back(&list), "is a test") != 0)
	{
		list_destroy(list);
		return (FAIL);
	}
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
	list_insert_at(&list, str3, 1);
	list_insert_at(&list, str2, 1);
	if (list_length(list) != 3)
	{
		list_destroy(list);
		return (FAIL);
	}
	if (string_compare(list_remove_back(&list), "a test") != 0)
	{
		list_destroy(list);
		return (FAIL);
	}
	if (string_compare(list_remove_back(&list), "is ") != 0)
	{
		list_destroy(list);
		return (FAIL);
	}
	if (string_compare(list_remove_back(&list), "This ") != 0)
	{
		list_destroy(list);
		return (FAIL);
	}
	return (PASS);
}

static int	test4(void)
{
	t_list	*list;

	list = 0;
	list_insert_at(&list, 0, 0);
	if (list_remove_back(&list) == 0)
		return (PASS);
	return (FAIL);
}

static int	test5(void)
{
	t_list	*list;

	list = 0;
	list_insert_at(&list, 0, 0);
	if (list_remove_back(&list) == 0)
		return (PASS);
	return (FAIL);
}

int	test_list_remove_back(void)
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
