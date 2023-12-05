/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_list_concat.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 12:53:56 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/05 12:53:57 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../build/plib_test.h"

static int	test1(void)
{
	t_list	*list1;
	t_list	*list2;
	t_list	*result;

	list1 = 0;
	list2 = list_create(0);
	result = list_concat(&list1, &list2);
	if (!result)
	{
		list_destroy(list2);
		return (PASS);
	}
	list_destroy(result);
	list_destroy(list2);
	return (FAIL);
}

static int	test2(void)
{
	t_list	*list1;
	t_list	*list2;
	t_list	*result;

	list1 = list_create(0);
	list2 = 0;
	result = list_concat(&list1, &list2);
	if (!result)
	{
		list_destroy(list1);
		return (PASS);
	}
	list_destroy(result);
	list_destroy(list1);
	return (FAIL);
}

static int	test3(void)
{
	t_list	*list1;
	t_list	*list2;
	t_list	*result;
	int	i;

	list1 = list_create(0);
	list2 = list_create(0);
	i = 1;
	while (i < 10)
	{
		list_insert_front(&list1, 0);
		list_insert_front(&list2, 0);
		++i;
	}
	result = list_concat(&list1, &list2);
	if (list_length(result) == 20)
	{
		list_destroy(result);
		return (PASS);
	}
	list_destroy(list1);
	list_destroy(list2);
	return (FAIL);
}


int	test_list_concat(void)
{
	test_print_verbose_start((char *)__FUNCTION__);
	test_print_verbose_test("test1", test1() == PASS);
	test_print_verbose_test("test2", test2() == PASS);
	test_print_verbose_test("test3", test3() == PASS);
	test_print_verbose_end();
	return (1);
}
