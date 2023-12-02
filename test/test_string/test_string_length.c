/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_string_length.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 16:14:51 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/02 16:14:51 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../build/plib_test.h"

static int	test1(void)
{
	char	*test1;

	test1 = "0123456789";
	if (string_length(test1) != 10)
		return (FAIL);
	return (PASS);
}

static int	test2(void)
{
	char	*test1;

	test1 = "";
	if (string_length(test1) != 0)
		return (FAIL);
	return (PASS);
}


static int	test3(void)
{
	char	*test1;

	test1 = 0;
	if (string_length(test1) != 0)
		return (FAIL);
	return (PASS);
}

int	test_string_length(void)
{
	test_print_verbose_start((char *)__FUNCTION__);
	test_print_verbose_test("test1", test1() == PASS);
	test_print_verbose_test("test2", test2() == PASS);
	test_print_verbose_test("test3", test3() == PASS);
	test_print_verbose_end();
	return (1);
}
