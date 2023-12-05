/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_string_split_destroy.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 16:23:55 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/03 17:43:58 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../build/plib_test.h"
#include <stdio.h>

static int	test1(void)
{
	char	**result;

	result = string_split_create(0);
	result = string_split_destroy(result, 100);
	if (!result)
		return (PASS);
	string_split_destroy(result, string_split_size(result));
	return (FAIL);
}

static int	test2(void)
{
	char	**result;

	result = string_split_create(42);
	result = string_split_destroy(result, 42);
	if (!result)
		return (PASS);
	string_split_destroy(result, string_split_size(result));
	return (FAIL);
}

int	test_string_split_destroy(void)
{
	test_print_verbose_start((char *)__FUNCTION__);
	test_print_verbose_test("test1", test1() == PASS);
	test_print_verbose_test("test2", test2() == PASS);
	// test_print_verbose_test("test3", test3() == PASS);
	// test_print_verbose_test("test4", test4() == PASS);
	test_print_verbose_end();
	return (1);
}
