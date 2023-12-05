/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_list_split_at.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:45:02 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/05 14:45:02 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../build/plib_test.h"

static int test1(void)
{
	t_list *list;
	t_list *list2;
	int     i;

	list = list_create(0);
	i = 1;
	while (i < 10)
	{
		list_insert_back(&list, 0);
		++i;
	}
	list2 = list_split_at(&list, 5);
	if (list_length(list2) == list_length(list))
	{
		list_destroy(list);
		list_destroy(list2);
		return (PASS);
	}
	list_destroy(list);
	list_destroy(list2);
	return (FAIL);
}

static int test2(void)
{
	t_list *list;
	t_list *list2;
	int     i;

	list = list_create(0);
	i = 1;
	while (i < 10)
	{
		list_insert_back(&list, 0);
		++i;
	}
	list2 = list_split_at(&list, 0);
	if (list_length(list2) == list_length(list))
	{
		list_destroy(list);
		return (PASS);
	}
	list_destroy(list);
	return (FAIL);
}

static int test3(void)
{
	t_list *list;
	t_list *list2;
	t_list *temp;
	char	*str;
	int     i;

	str = "This";
	list = list_create(0);
	i = 1;
	while (i < 10)
	{
		list_insert_back(&list, 0);
		++i;
	}
	temp = list_get_tail(&list);
	temp->data = str;
	list2 = list_split_at(&list, 42);
	if (string_compare(list2->data, str) == 0)
	{
		list_destroy(list);
		return (PASS);
	}
	list_destroy(list);
	return (FAIL);
}

static int test4(void)
{
	t_list	*list;

	list = 0;
	if (list_split_at(&list, 42) == 0)
		return (PASS);
	return (FAIL);
}

static int test5(void)
{
	if (list_split_at(0, 42) == 0)
		return (PASS);
	return (FAIL);
}

int test_list_split_at(void)
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
