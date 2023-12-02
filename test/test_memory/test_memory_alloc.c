/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_memory_alloc.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 12:21:45 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/02 12:21:46 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../build/plib_test.h"

static int	test1(void)
{
	void	*ptr;

	ptr = 0;
	ptr = memory_alloc(0, 0);
	if (ptr)
	{
		memory_dealloc(ptr);
		return (FAIL);
	}
	return (PASS);
}

static int	test2(void)
{
	void	*ptr;

	ptr = 0;
	ptr = memory_alloc(1, 2147483647);
	if (ptr)
	{
		memory_dealloc(ptr);
		return (FAIL);
	}
	return (PASS);
}

static int	test3(void)
{
	void	*ptr;

	ptr = 0;
	ptr = memory_alloc(1, 1);
	if (ptr)
	{
		memory_dealloc(ptr);
		return (PASS);
	}
	else
		return (FAIL);
}

static int	test4(void)
{
	void	*ptr;

	ptr = 0;
	ptr = memory_alloc(42, 42);
	if (ptr)
	{
		memory_dealloc(ptr);
		return (PASS);
	}
	else
		return (FAIL);
}

int	test_memory_alloc(void)
{
	test_print_verbose_start((char *)__FUNCTION__);
	test_print_verbose_test("test1", test1() == PASS);
	test_print_verbose_test("test2", test2() == PASS);
	test_print_verbose_test("test3", test3() == PASS);
	test_print_verbose_test("test4", test4() == PASS);
	test_print_verbose_end();
	return (1);
}
