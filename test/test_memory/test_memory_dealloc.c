/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_memory_dealloc.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 12:21:52 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/02 12:21:53 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../build/plib_test.h"

static int	test1(void)
{
	void	*ptr;

	ptr = memory_alloc(1, 1);
	ptr = memory_dealloc(ptr);
	if (!ptr)
		return (PASS);
	return (FAIL);
}

static int	test2(void)
{
	void	*ptr;

	ptr = memory_alloc(0, 1);
	ptr = memory_dealloc(ptr);
	if (!ptr)
		return (PASS);
	return (FAIL);
}

static int	test3(void)
{
	void	*ptr;

	ptr = 0;
	ptr = memory_dealloc(ptr);
	if (!ptr)
		return (PASS);
	return (FAIL);
}

int	test_memory_dealloc(void)
{
	test_print_verbose_start((char *)__FUNCTION__);
	test_print_verbose_test("test1", test1() == PASS);
	test_print_verbose_test("test2", test2() == PASS);
	test_print_verbose_test("test3", test3() == PASS);
	test_print_verbose_end();
	return (1);
}
