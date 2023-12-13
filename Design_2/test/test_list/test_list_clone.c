/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_list_clone.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 12:45:23 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/05 12:45:26 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../build/plib_test.h"

static int test1(void)
{
	t_list *list;
	t_list *clone;
	char   *str;

	str = "This is a test";
	list = list_create(str);
	if (!list)
		return (FAIL);
	clone = list_clone(&list);
	if (!clone)
	{
		list_destroy(list);
		return (FAIL);
	}
	if (string_compare(clone->data, str) == 0)
	{
		list_destroy(clone);
		list_destroy(list);
		return (PASS);
	}
	list_destroy(list);
	return (FAIL);
}

static int test2(void)
{
	t_list *list;
	t_list *clone;

	list = list_create(0);
	if (!list)
		return (FAIL);
	clone = list_clone(&list);
	if (!clone)
		return (FAIL);
	list_destroy(clone);
	list_destroy(list);
	return (PASS);
}

static int test3(void)
{
	t_list *clone;

	clone = list_clone(0);
	if (!clone)
		return (PASS);
	list_destroy(clone);
	return (FAIL);
}

static int test4(void)
{
	t_list *list;
	t_list *clone;
	int     i;

	list = list_create(0);
	i = 0;
	while (i < 1000)
	{
		list_insert_front(&list, 0);
		++i;
	}
	clone = list_clone(&list);
	if (!clone)
		return (FAIL);
	if (list_length(clone) != list_length(list))
	{
		list_destroy(list);
		list_destroy(clone);
		return (FAIL);
	}
	list_destroy(list);
	list_destroy(clone);
	return (PASS);
}

int test_list_clone(void)
{
	test_print_verbose_start((char *) __FUNCTION__);
	test_print_verbose_test("test1", test1() == PASS);
	test_print_verbose_test("test2", test2() == PASS);
	test_print_verbose_test("test3", test3() == PASS);
	test_print_verbose_test("test4", test4() == PASS);
	test_print_verbose_end();
	return (1);
}
