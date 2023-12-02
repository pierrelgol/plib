/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_string_filter.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 16:13:44 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/02 16:13:45 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../build/plib_test.h"

static int	test1(void)
{
	char	*test1;
	char	*test2;

	test1 = "     3 . 1 4        ";
	test2 = string_filter(test1, ' ');
	if (string_compare(test2, "3.14") != 0)
	{
		string_destroy(test2);
		return (FAIL);
	}
	string_destroy(test2);
	return (PASS);
}

static int	test2(void)
{
	char	*test1;
	char	*test2;

	test1 = "";
	test2 = string_filter(test1, ' ');
	if (string_compare(test2, "") == 0)
	{
		string_destroy(test2);
		return (PASS);
	}
	string_destroy(test2);
	return (FAIL);
}

static int	test3(void)
{
	char	*test1;
	char	*test2;

	test1 = 0;
	test2 = string_filter(test1, ' ');
	if (!test2)
		return (PASS);
	string_destroy(test2);
	return (FAIL);
}


static int	test4(void)
{
	char	*test1;
	char	*test2;

	test1 = "     3 . 1 4        ";
	test2 = string_filter(test1, 'y');
	if (string_compare(test2, "     3 . 1 4        ") != 0)
	{
		string_destroy(test2);
		return (FAIL);
	}
	string_destroy(test2);
	return (PASS);
}

int	test_string_filter(void)
{
	test_print_verbose_start((char *)__FUNCTION__);
	test_print_verbose_test("test1", test1() == PASS);
	test_print_verbose_test("test2", test2() == PASS);
	test_print_verbose_test("test3", test3() == PASS);
	test_print_verbose_test("test4", test4() == PASS);
	test_print_verbose_end();
	return (1);
}
