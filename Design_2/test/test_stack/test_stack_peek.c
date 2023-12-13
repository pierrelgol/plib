/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_stack_peek.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 12:28:51 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/08 12:28:51 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../build/plib_test.h"
#include <stdio.h>

static int test1(void)
{
	t_stack *stack;

	stack = 0;
	if (stack_peek(stack) != 0)
		return (FAIL);
	return (PASS);
}

static int test2(void)
{
	t_stack *stack;

	stack = stack_create(0);
	stack->count = 0;
	if (stack_peek(stack) != 0)
		return (FAIL);
	return (PASS);
}

static int test3(void)
{
	t_stack *stack;
	char    *str1;
	char    *str2;
	char    *str3;

	str1 = " a test";
	str2 = " is";
	str3 = "This";
	stack = stack_create(str1);
	stack_push(stack, str2);
	stack_push(stack, str3);
	if (string_compare(stack_peek(stack), str3) != 0)
	{
		stack_destroy(stack);
		return (FAIL);
	}
	stack_pop(stack);
	if (string_compare(stack_peek(stack), str2) != 0)
	{
		stack_destroy(stack);
		return (FAIL);
	}
	stack_pop(stack);
	if (string_compare(stack_peek(stack), str1) != 0)
	{
		stack_destroy(stack);
		return (FAIL);
	}
	stack_pop(stack);
	if (string_compare(stack_peek(stack), "") != 0)
	{
		stack_destroy(stack);
		return (FAIL);
	}
	stack_destroy(stack);
	return (PASS);
}


int test_stack_peek(void)
{
	test_print_verbose_start((char *) __FUNCTION__);
	test_print_verbose_test("test1", test1() == PASS);
	test_print_verbose_test("test2", test2() == PASS);
	test_print_verbose_test("test3", test3() == PASS);
	// test_print_verbose_test("test4", test4() == PASS);
	test_print_verbose_end();
	return (1);
}

