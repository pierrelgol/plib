/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_string_search_replace_all.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 16:22:18 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/02 16:22:20 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../build/plib_test.h"

static int test1(void)
{
	char	*test1;
	char	*test2;
	char	*result;

	test1 = 0;
	test2 = "This";
	result = string_search_replace_all(test1, test2, "That");
	if (!result)
		return (PASS);
	return (FAIL);
}

static int test2(void)
{
	char	*test1;
	char	*test2;
	char	*result;

	test1 = "This";
	test2 = 0;
	result = string_search_replace_all(test1, test2, "That");
	if (!result)
		return (PASS);
	return (FAIL);
}

static int test3(void)
{
	char	*test1;
	char	*test2;
	char	*result;

	test1 = "This";
	test2 = "his";
	result = string_search_replace_all(test1, test2, 0);
	if (!result)
		return (PASS);
	return (FAIL);
}

static int test4(void)
{
	char	*test1;
	char	*test2;
	char	*result;

	test1 = string_clone("This This This");
	test2 = "his";
	result = string_search_replace_all(test1, test2, "hat");
	if (string_compare(result, "That That That") == 0)
	{
		string_destroy(result);
		return (PASS);
	}
	string_destroy(result);
	return (FAIL);
}

static int test5(void)
{
	char	*test1;
	char	*test2;
	char	*result;

	test1 = string_clone("This This This");
	test2 = "his";
	result = string_search_replace_all(test1, test2, "hattttttt");
	if (string_compare(result, "That That That") == 0)
	{
		string_destroy(result);
		return (PASS);
	}
	string_destroy(result);
	return (FAIL);
}

static int test6(void)
{
	char	*test1;
	char	*test2;
	char	*result;

	test1 = string_clone("This This This");
	test2 = "his";
	result = string_search_replace_all(test1, test2, "ha");
	if (string_compare(result, "Thas Thas Thas") == 0)
	{
		string_destroy(result);
		return (PASS);
	}
	string_destroy(result);
	return (FAIL);
}

int test_string_search_replace_all(void)
{
	test_print_verbose_start((char *) __FUNCTION__);
	test_print_verbose_test("test1", test1() == PASS);
	test_print_verbose_test("test2", test2() == PASS);
	test_print_verbose_test("test3", test3() == PASS);
	test_print_verbose_test("test4", test4() == PASS);
	test_print_verbose_test("test5", test5() == PASS);
	test_print_verbose_test("test6", test6() == PASS);
	test_print_verbose_end();

	return (1);
}


