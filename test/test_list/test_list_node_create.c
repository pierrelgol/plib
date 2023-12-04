/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_list_node_create.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 13:10:15 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/04 13:10:16 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../build/plib_test.h"

static int test1(void)
{
	t_node *node;

	node = list_node_create("This");
	if (!node)
		return (FAIL);
	if (string_compare(node->data, "This") == 0)
	{
		list_node_destroy(node);
		return (PASS);
	}
	list_node_destroy(node);
	return (FAIL);
}

static int test2(void)
{
	t_node *node;

	node = list_node_create(0);
	if (!node)
		return (FAIL);
	if (string_compare(node->data, "") == 0)
	{
		list_node_destroy(node);
		return (PASS);
	}
	list_node_destroy(node);
	return (FAIL);
}

int test_list_node_create(void)
{
	test_print_verbose_start((char *) __FUNCTION__);
	test_print_verbose_test("test1", test1() == PASS);
	test_print_verbose_test("test2", test2() == PASS);
	// test_print_verbose_test("test3", test3() == PASS);
	// test_print_verbose_test("test4", test4() == PASS);
	// test_print_verbose_test("test5", test5() == PASS);
	test_print_verbose_end();

	return (1);
}
