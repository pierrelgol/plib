/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_list_size.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 13:11:28 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/04 13:11:30 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../build/plib_test.h"


static int test1(void)
{
	t_node node1;
	t_node node2;
	t_node node3;
	t_list list;

	node1.next = &node2;
	node2.next = &node3;
	node3.next = 0;
	list.head = &node1;
	if (list_size(&list) != 3)
		return (FAIL);
	return (PASS);
}

static int test2(void)
{
	t_node node1;
	t_list list;

	node1.next = 0;
	list.head = &node1;
	if (list_size(&list) != 1)
		return (FAIL);
	return (PASS);
}


static int test3(void)
{
	t_list list;

	list.head = 0;
	if (list_size(&list) != 0)
		return (FAIL);
	return (PASS);
}

int test_list_size(void)
{
	test_print_verbose_start((char *) __FUNCTION__);
	test_print_verbose_test("test1", test1() == PASS);
	test_print_verbose_test("test2", test2() == PASS);
	test_print_verbose_test("test3", test3() == PASS);
	test_print_verbose_end();

	return (1);
}
