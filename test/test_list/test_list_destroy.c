/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_list_destroy.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 08:50:20 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/05 08:50:21 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../build/plib_test.h"

static int test1(void)
{
	t_list *list;
	char   *str;

	str = "This is a test";
	list = list_create(str);
	if (!list)
		return (FAIL);
	if (list_destroy(list) == 0)
		return (PASS);
	list_destroy(list);
	return (FAIL);
}

static int test2(void)
{
	t_list *list;

	list = 0;
	if (list_destroy(list) == 0)
		return (PASS);
	list_destroy(list);
	return (PASS);
}

int test_list_destroy(void)
{
	test_print_verbose_start((char *) __FUNCTION__);
	test_print_verbose_test("test1", test1() == PASS);
	test_print_verbose_test("test2", test2() == PASS);
	test_print_verbose_end();

	return (1);
}

