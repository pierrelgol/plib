/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_stack_destroy.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 10:32:59 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/08 10:33:00 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../build/plib_test.h"

static int	test1(void)
{
	t_stack	*stack;
	char	*str;

	str = "This is a test";
	stack = stack_create(str);
	if (!stack)
		return (FAIL);
	if (stack_destroy(stack) == 0)
		return (PASS);
	return (FAIL);
}

static int	test2(void)
{
	t_stack *stack;
	char	*str1;
	char	*str2;
	char	*str3;

	str1 = "This";
	str2 = " is";
	str3 = " a test";
	stack = stack_create(str1);
	stack_push(stack, str2);
	stack_push(stack, str3);
	stack_pop(stack);
	if (stack_destroy(stack) == 0)
		return (PASS);
	stack_destroy(stack);
	return (FAIL);
}

 /* oops someone deleted a node */

static int	test3(void)
{
	t_stack	*stack;

	stack = stack_create(0);
	if (!stack)
		return (FAIL);
	stack->top = memory_dealloc(stack->top); 
	if (stack_destroy(stack) == 0)
		return (PASS);
	return (FAIL);
}

 /* oops someone deleted a node */

static int	test4(void)
{
	t_stack	*stack;

	stack = stack_create(0);
	if (!stack)
		return (FAIL);
	stack->free_node = memory_dealloc(stack->free_node); 
	if (stack_destroy(stack) == 0)
		return (PASS);
	return (FAIL);
}

static int	test5(void)
{
	t_stack	*stack;

	stack = 0;
	if (stack_destroy(stack) == 0)
		return (PASS);
	return (FAIL);
}

int	test_stack_destroy(void)
{
	test_print_verbose_start((char *)__FUNCTION__);
	test_print_verbose_test("test1", test1() == PASS);
	test_print_verbose_test("test2", test2() == PASS);
	test_print_verbose_test("test3", test3() == PASS);
	test_print_verbose_test("test4", test4() == PASS);
	test_print_verbose_test("test5", test5() == PASS);
	test_print_verbose_end();
	return (1);
}

