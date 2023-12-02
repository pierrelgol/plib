/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_memory_set.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 12:22:42 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/02 12:22:44 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../build/plib_test.h"

static int	test1(void)
{
	void	*ptr;

	ptr = 0;
	memory_set(ptr, 0, 10);
	if (!ptr)
		return (PASS);
	return (FAIL);
}

static int	test2(void)
{
	void	*ptr;

	ptr = memory_alloc(1, 42);
	if (!memory_set(ptr, 1, 0))
	{
		memory_dealloc(ptr);
		return (PASS);
	}
	return (FAIL);
}

static int	test3(void)
{
	char	*test;
	char	*ptr;

	test = "111111111111111111111111111111111111111111";
	ptr = memory_alloc(1, 42);
	memory_set(ptr, '1', 42);
	if (memory_compare(ptr, test, 42) == 0)
	{
		memory_dealloc(ptr);
		return (PASS);
	}
	memory_dealloc(ptr);
	return (FAIL);
}

static int	test4(void)
{
	void	*ptr;

	ptr = memory_alloc(1, 42);
	if (!memory_set(ptr, 1, 0))
	{
		memory_dealloc(ptr);
		return (PASS);
	}
	memory_dealloc(ptr);
	return (FAIL);
}

int	test_memory_set(void)
{
	test_print_verbose_start((char *)__FUNCTION__);
	test_print_verbose_test("test1", test1() == PASS);
	test_print_verbose_test("test2", test2() == PASS);
	test_print_verbose_test("test3", test3() == PASS);
	test_print_verbose_test("test4", test4() == PASS);
	test_print_verbose_end();
	return (1);
}
