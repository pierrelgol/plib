/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_list_peek_at.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 15:12:17 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/04 15:12:17 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../build/plib_test.h"

static int test1(void)
{
	t_list *list;
	char   *str;

	str = "This";
	list = list_create(str);
	if (string_compare(list_peek_at(list, 0), "This") == 0)
	{
		list_destroy(list);
		return (PASS);
	}
	list_destroy(list);
	return (FAIL);
}

int test_list_peek_at(void)
{
	test_print_verbose_start((char *) __FUNCTION__);
	test_print_verbose_test("test1", test1() == PASS);
	// test_print_verbose_test("test2", test2() == PASS);
	// test_print_verbose_test("test3", test3() == PASS);
	test_print_verbose_end();

	return (1);
}
