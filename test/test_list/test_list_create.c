/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_list_create.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 13:10:26 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/04 13:10:27 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../build/plib_test.h"


static int test1(void)
{
	t_list *list;

	list = list_create("This");
	if (!list)
		return (FAIL);
	if (!list->head || !list->tail)
		return (FAIL);
	if (string_compare("This", list->head->data) == 0)
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
	if (!list)
		return (FAIL);
	if (!list->head || !list->tail)
		return (FAIL);
	if (string_compare("", list->head->data) == 0)
	{
		list_destroy(list);
		return (PASS);
	}
	list_destroy(list);
	return (FAIL);
}


int test_list_create(void)
{
	test_print_verbose_start((char *) __FUNCTION__);
	test_print_verbose_test("test1", test1() == PASS);
	test_print_verbose_test("test2", test2() == PASS);
	test_print_verbose_end();

	return (1);
}

