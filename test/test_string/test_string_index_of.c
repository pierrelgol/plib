/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_string_index_of.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 16:14:25 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/02 16:14:26 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../build/plib_test.h"

static int	test1(void)
{
	char	*test1;
	int	test2;

	test1 = "This is a test";
	test2 = string_index_of(test1,  'z');
	if (test2 == -1)
		return (PASS);
	return (FAIL);
}


static int	test2(void)
{
	char	*test1;
	int	test2;

	test1 = 0;
	test2 = string_index_of(test1,  'z');
	if (test2 == -1)
		return (PASS);
	return (FAIL);
}

static int	test3(void)
{
	char	*test1;
	int	test2;

	test1 = "This is a test";
	test2 = string_index_of(test1,  'T');
	if (test1[test2] == 'T')
		return (PASS);
	return (FAIL);
}

static int	test4(void)
{
	char	*test1;
	int	test2;

	test1 = "This is a test";
	test2 = string_index_of(test1,  't');
	if (test1[test2] == 't')
		return (PASS);
	return (FAIL);
}


int	test_string_index_of(void)
{
	test_print_verbose_start((char *)__FUNCTION__);
	test_print_verbose_test("test1", test1() == PASS);
	test_print_verbose_test("test2", test2() == PASS);
	test_print_verbose_test("test3", test3() == PASS);
	test_print_verbose_test("test4", test4() == PASS);
	test_print_verbose_end();
	return (1);
}

