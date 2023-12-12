/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_list_length.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 08:51:58 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/05 08:51:58 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../build/plib_test.h"

static int	test1(void)
{
	t_list	*list;
	char	*str;
	int		i;

	str = "This is a test";
	list = list_create(str);
	i = 5;
	while (i--)
		list_insert_back(&list, str);
	if (list_length(list) == 6)
	{
		list_destroy(list);
		return (PASS);
	}
	list_destroy(list);
	return (FAIL);
}

static int	test2(void)
{
	t_list	*list;
	char	*str;
	int		i;

	str = "This is a test";
	list = list_create(str);
	i = 0;
	while (i--)
		list_insert_back(&list, str);
	if (list_length(list) == 1)
	{
		list_destroy(list);
		return (PASS);
	}
	list_destroy(list);
	return (FAIL);
}

static int	test3(void)
{
	t_list	*list;
	char	*str;
	int		i;

	str = "This is a test";
	list = list_create(str);
	i = 41;
	while (i--)
		list_insert_back(&list, str);
	if (list_length(list) == 42)
	{
		list_destroy(list);
		return (PASS);
	}
	list_destroy(list);
	return (FAIL);
}

static int	test4(void)
{
	t_list	*list;

	list = 0;
	if (list_length(list) == 0)
	{
		list_destroy(list);
		return (PASS);
	}
	list_destroy(list);
	return (FAIL);
}

int	test_list_length(void)
{
	test_print_verbose_start((char *)__FUNCTION__);
	test_print_verbose_test("test1", test1() == PASS);
	test_print_verbose_test("test2", test2() == PASS);
	test_print_verbose_test("test3", test3() == PASS);
	test_print_verbose_test("test4", test4() == PASS);
	test_print_verbose_end();
	return (1);
}
