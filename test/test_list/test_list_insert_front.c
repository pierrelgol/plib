/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_list_insert_front.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 08:56:23 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/05 08:56:23 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../build/plib_test.h"

static int test1(void)
{
	t_list *list;
	char   *str;
	char   *temp;
	int     i;

	str = string_clone("This is a test");
	list = list_create(str);
	i = 0;
	while (i < 10)
	{
		temp = string_slice(str, 0, string_length(str) - i);
		list_insert_front(&list, temp);
		++i;
	}
	i = 0;
	while (i < 10)
	{
		temp = list_remove_front(&list);
		if (memory_compare(temp, str, string_length(str) - 10 + i) != 0)
			break;
		string_destroy(temp);
		++i;
	}
	if (i == 10)
	{
		list_destroy(list);
		return (PASS);
	}
	list_destroy(list);
	return (FAIL);
}

static int test2(void)
{
	t_list	*list;
	char	*str;

	list = 0;
	str = "This is a test";
	list_insert_front(&list, str);
	if (string_compare(list->data, str) == 0)
	{
		list_destroy(list);
		return (PASS);
	}
	list_destroy(list);
	return (FAIL);
}

static int test3(void)
{
	t_list	*list;

	list = 0;
	list_insert_front(&list, 0);
	if (string_compare(list->data, "") == 0)
	{
		list_destroy(list);
		return (PASS);
	}
	list_destroy(list);
	return (FAIL);
}

int test_list_insert_front(void)
{
	test_print_verbose_start((char *) __FUNCTION__);
	test_print_verbose_test("test1", test1() == PASS);
	test_print_verbose_test("test2", test2() == PASS);
	test_print_verbose_test("test3", test3() == PASS);
	test_print_verbose_end();

	return (1);
}
