/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_list_get_tail.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:43:40 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/05 14:43:42 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../build/plib_test.h"

static int test1(void)
{
	t_list *list;

	list = list_create(0);
	if (list == list_get_tail(&list))
	{
		list_destroy(list);
		return (PASS);
	}
	list_destroy(list);
	return (FAIL);
}

static int test2(void)
{
	if (list_get_tail(0) == 0)
		return (PASS);
	return (FAIL);
}

static int test3(void)
{
	t_list *list;
	t_list *temp;

	list = list_create(0);
	temp = list_insert_at(&list, 0, 1);
	if (temp == list_get_tail(&list))
	{
		list_destroy(list);
		return (PASS);
	}
	list_destroy(list);
	return (FAIL);
}


int test_list_get_tail(void)
{
	test_print_verbose_start((char *) __FUNCTION__);
	test_print_verbose_test("test1", test1() == PASS);
	test_print_verbose_test("test2", test2() == PASS);
	test_print_verbose_test("test3", test3() == PASS);
	test_print_verbose_end();
	return (1);
}

