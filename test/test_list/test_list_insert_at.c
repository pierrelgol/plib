/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_list_insert_at.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 13:10:48 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/04 13:10:48 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../build/plib_test.h"


static int test1(void)
{
	t_list *list;

	list = list_create(0);
	list = list_insert_at(list, 0, 0);
	if (list_size(list) == 2)
	{
		list_destroy(list);
		return (PASS);
	}
	list_destroy(list);
	return (FAIL);
}

static int test2(void)
{
	t_list *list;

	list = list_create(0);
	list = list_insert_at(list, 0, 1);
	if (list_size(list) == 2)
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

	list = list_create(0);
	list = list_insert_at(list, 0, 1);
	list = list_insert_at(list, 0, 1);
	if (list_size(list) == 3)
	{
		list_destroy(list);
		return (PASS);
	}
	list_destroy(list);
	return (FAIL);
}

static int test4(void)
{
	t_list *list;

	list = list_create(0);
	list = list_insert_at(list, 0, 1);
	list = list_insert_at(list, 0, 42);
	if (list_size(list) == 3)
	{
		list_destroy(list);
		return (PASS);
	}
	list_destroy(list);
	return (FAIL);
}


static int test5(void)
{
	t_list *list;

	list = 0;
	if (list_insert_at(list, 0, 10) == 0)
		return (PASS);
	return (FAIL);
}


int test_list_insert_at(void)
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
