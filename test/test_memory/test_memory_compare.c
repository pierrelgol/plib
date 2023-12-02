/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_memory_compare.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 12:22:03 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/02 12:22:04 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../build/plib_test.h"

static int	test1(void)
{
	char	*test1;
	char	*test2;

	test1 = 0;
	test2 = 0;
	if (memory_compare(test1, test2, 10) != 0)
		return (FAIL);
	return (PASS);
}

static int	test2(void)
{
	char	*test1;
	char	*test2;

	test1 = "This";
	test2 = 0;
	if (memory_compare(test1, test2, 10) != 0)
		return (FAIL);
	return (PASS);
}

static int	test3(void)
{
	char	*test1;
	char	*test2;

	test1 = 0;
	test2 = "This";
	if (memory_compare(test1, test2, 10) != 0)
		return (FAIL);
	return (PASS);
}

static int	test4(void)
{
	char	*test1;
	char	*test2;

	test1 = "This";
	test2 = "This";
	if (memory_compare(test1, test2, 4) != 0)
		return (FAIL);
	return (PASS);
}

static int	test5(void)
{
	char	*test1;
	char	*test2;

	test1 = "This";
	test2 = "Thisa";
	if (memory_compare(test1, test2, 5) < 0)
		return (PASS);
	return (FAIL);
}

static int	test6(void)
{
	char	*test1;
	char	*test2;

	test1 = "Thisa";
	test2 = "This";
	if (memory_compare(test1, test2, 5) > 0)
		return (PASS);
	return (FAIL);
}

int	test_memory_compare(void)
{
	test_print_verbose_start((char *)__FUNCTION__);
	test_print_verbose_test("test1", test1() == PASS);
	test_print_verbose_test("test2", test2() == PASS);
	test_print_verbose_test("test3", test3() == PASS);
	test_print_verbose_test("test4", test4() == PASS);
	test_print_verbose_test("test5", test5() == PASS);
	test_print_verbose_test("test6", test6() == PASS);
	test_print_verbose_end();
	return (1);
}
