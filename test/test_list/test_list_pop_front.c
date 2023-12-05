/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_list_pop_front.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 13:09:00 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/05 13:09:00 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../build/plib_test.h"

static int test1(void)
{
	t_list *list;
	t_list *temp;
	char   *str1;
	char   *str2;

	str1 = "This";
	str2 = "is a test";
	list = list_create(str1);
	list_insert_at(&list, str2, 1);
	if (list_length(list) != 2)
	{
		list_destroy(list);
		return (FAIL);
	}
	temp = list_pop_front(&list);
	if (string_compare(temp->data, "This") != 0)
	{
		list_destroy(list);
		return (FAIL);
	}
	if (temp)
		memory_dealloc(temp);
	temp = list_pop_front(&list);
	if (string_compare(temp->data, "is a test") != 0)
	{
		list_destroy(list);
		return (FAIL);
	}
	if (temp)
		memory_dealloc(temp);
	list_destroy(list);
	return (PASS);
}

static int test2(void)
{
	t_list *list;
	t_list *temp;
	char   *str1;
	char   *str2;

	str1 = "This";
	str2 = "is a test";
	list = list_create(str1);
	list_insert_at(&list, str2, 0);
	if (list_length(list) != 2)
	{
		list_destroy(list);
		return (FAIL);
	}
	temp = list_pop_front(&list);
	if (string_compare(temp->data, "is a test") != 0)
	{
		list_destroy(list);
		return (FAIL);
	}
	if (temp)
		memory_dealloc(temp);
	temp = list_pop_front(&list);
	if (string_compare(temp->data, "This") != 0)
	{
		list_destroy(list);
		return (FAIL);
	}
	if (temp)
		memory_dealloc(temp);
	list_destroy(list);
	return (PASS);
}

static int test3(void)
{
	t_list *list;
	t_list *temp;
	char   *str1;
	char   *str2;
	char   *str3;

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
	temp = list_pop_front(&list);
	if (string_compare(temp->data, "This ") != 0)
	{
		list_destroy(list);
		return (FAIL);
	}
	if (temp)
		memory_dealloc(temp);
	temp = list_pop_front(&list);
	if (string_compare(temp->data, "is ") != 0)
	{
		list_destroy(list);
		return (FAIL);
	}
	if (temp)
		memory_dealloc(temp);
	temp = list_pop_front(&list);
	if (string_compare(temp->data, "a test") != 0)
	{
		list_destroy(list);
		return (FAIL);
	}
	if (temp)
		memory_dealloc(temp);
	list_destroy(list);
	return (PASS);
}

static int test4(void)
{
	if (list_pop_front(0) == 0)
		return (PASS);
	return (FAIL);
}

static int test5(void)
{
	t_list *list;
	t_list *temp;

	list = 0;
	list_insert_at(&list, 0, 0);
	temp = list_pop_front(&list);
	if (temp)
	{
		list_destroy(temp);
		return (PASS);
	}
	list_destroy(temp);
	return (FAIL);
}

int test_list_pop_front(void)
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
