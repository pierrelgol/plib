/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_list_push_back.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:19:25 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/05 14:19:25 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../build/plib_test.h"

static int test1(void)
{
	t_list *list;
	t_list *temp;

	list = list_create(0);
	temp = list_create(0);
	list_push_back(&list, temp);
	if (list_length(list) == 2)
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
	list_push_back(&list, 0);
	if (list_length(list) == 1)
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
	t_list *temp;

	list = 0;
	temp = list_create(0);
	list_push_back(&list, temp);
	if (list_length(list) == 1)
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
	t_list *temp;
	int	i;

	list = 0;
	temp = list_create(0);
	i = 0;
	while (i < 10)
	{
		list_insert_back(&list, 0);
		++i;
	}
	list_push_back(&list, temp);
	if (list_length(list) == 11)
	{
		list_destroy(list);
		return (PASS);
	}
	list_destroy(list);
	return (FAIL);
}

int test_list_push_back(void)
{
	test_print_verbose_start((char *) __FUNCTION__);
	test_print_verbose_test("test1", test1() == PASS);
	test_print_verbose_test("test2", test2() == PASS);
	test_print_verbose_test("test3", test3() == PASS);
	test_print_verbose_test("test4", test4() == PASS);
	test_print_verbose_end();
	return (1);
}
