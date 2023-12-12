/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_list_push_front.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 13:53:24 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/05 13:53:25 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../build/plib_test.h"

static int test1(void)
{
	t_list *list1;
	t_list *list2;
	t_list *temp;
	char   *str;

	str = "This";
	list1 = list_create(str);
	temp = list_pop_front(&list1);
	list_push_front(&list2, temp);
	if (string_compare(list2->data, str) == 0)
	{
		list_destroy(list2);
		return (PASS);
	}
	list_destroy(list1);
	list_destroy(list2);
	return (FAIL);
}

static int test2(void)
{
	t_list *list1;
	t_list *temp;
	char   *str1;
	char   *str2;
	char   *str3;

	str1 = "This";
	str2 = " is";
	str3 = " a test";

	list1 = list_create(str2);
	list_insert_back(&list1, str3);

	temp = list_create(str1);
	list_push_front(&list1, temp);
	if (string_compare(list1->data, str1) == 0)
	{
		list_destroy(list1);
		return (PASS);
	}
	list_destroy(list1);
	return (FAIL);
}

static int test3(void)
{
	t_list *list1;

	list1 = list_create(0);
	if (list_push_front(&list1, 0) == 0)
	{
		list_destroy(list1);
		return (PASS);
	}
	list_destroy(list1);
	return (FAIL);
}

static int test4(void)
{
	t_list *list1;

	list1 = 0;
	if (list_push_front(&list1, 0) == 0)
		return (PASS);
	return (FAIL);
}

int test_list_push_front(void)
{
	test_print_verbose_start((char *) __FUNCTION__);
	test_print_verbose_test("test1", test1() == PASS);
	test_print_verbose_test("test2", test2() == PASS);
	test_print_verbose_test("test3", test3() == PASS);
	test_print_verbose_test("test4", test4() == PASS);
	test_print_verbose_end();
	return (1);
}
