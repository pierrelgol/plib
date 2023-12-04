/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_list_node_at.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 13:11:38 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/04 13:11:38 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../build/plib_test.h"


static int test1(void)
{
	t_node node1;
	t_node node2;
	t_node node3;

	node1.next = &node2;
	node2.next = &node3;
	node3.next = 0;
	if (list_node_at(&node1, 0) != &node1)
		return (FAIL);
	if (list_node_at(&node1, 1) != &node2)
		return (FAIL);
	if (list_node_at(&node1, 2) != &node3)
		return (FAIL);
	return (PASS);
}

static int test2(void)
{
	t_node node1;
	t_node node2;
	t_node node3;

	node1.next = &node2;
	node2.next = &node3;
	node3.next = 0;
	if (list_node_at(&node1, 10) == 0)
		return (PASS);
	return (FAIL);
}


static int test3(void)
{
	if (list_node_at(0, 10) == 0)
		return (PASS);
	return (FAIL);
}

int test_list_node_at(void)
{
	test_print_verbose_start((char *) __FUNCTION__);
	test_print_verbose_test("test1", test1() == PASS);
	test_print_verbose_test("test2", test2() == PASS);
	test_print_verbose_test("test3", test3() == PASS);
	test_print_verbose_end();

	return (1);
}
