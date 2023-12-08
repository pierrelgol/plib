/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_stack_create.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 10:30:20 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/08 10:30:20 by plgol.perso      ###   ########.fr       */
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
	if (string_compare(stack->top->data, str) == 0)
	{
		stack_destroy(stack);
		return (PASS);
	}
	stack_destroy(stack);
	return (FAIL);
}

static int	test2(void)
{
	t_stack *stack;

	stack = stack_create(0);
	if (!stack)
		return (FAIL);
	stack_destroy(stack);
	return (PASS);
}

int	test_stack_create(void)
{
	test_print_verbose_start((char *)__FUNCTION__);
	test_print_verbose_test("test1", test1() == PASS);
	test_print_verbose_test("test2", test2() == PASS);
	test_print_verbose_end();
	return (1);
}

