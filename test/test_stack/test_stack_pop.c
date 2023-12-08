/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_stack_pop.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 11:41:07 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/08 11:41:08 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../build/plib_test.h"
#include <stdio.h>

static int test1(void)
{
	t_stack *stack;

	stack = 0;
	if (stack_pop(stack) != 0)
		return (FAIL);
	return (PASS);
}

static int test2(void)
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
	if (string_compare(stack_pop(stack), str3) != 0)
	{
		stack_destroy(stack);
		return (FAIL);
	}
	if (string_compare(stack_pop(stack), str2) != 0)
	{
		stack_destroy(stack);
		return (FAIL);
	}
	if (string_compare(stack_pop(stack), str1) != 0)
	{
		stack_destroy(stack);
		return (FAIL);
	}
	stack_destroy(stack);
	return (PASS);
}

static int test3(void)
{
	t_stack     *stack;
	unsigned int previous_size;
	unsigned int i;

	stack = stack_create(0);
	previous_size = stack->size;
	i = 128;
	while (i)
	{
		if (previous_size != stack->size)
		{
			previous_size = stack->size;
			// printf("\n[size][%d][count][%d]\n",stack->size, stack->count);
		}
		stack_push(stack, 0);
		--i;
	}

	i = 128;
	while (i)
	{
		if (previous_size != stack->size)
		{
			previous_size = stack->size;
			// printf("\n[size][%d][count][%d]\n",stack->size, stack->count);
		}
		stack_pop(stack);
		--i;
	}
	stack_destroy(stack);
	return (PASS);
}

// static int i = 0;

// static void	print_stack(t_list *list)
// {
// 	if (!list)
// 	{
// 		printf("\n");
// 		return;
// 	}
// 	printf("%d, ",i++);
// 	print_stack(list->next);
// }

static int	test4(void)
{
	t_stack	*stack;
	unsigned int random_pop;
	unsigned int random_push;
	unsigned int cycles;

	stack = stack_create(0);
	cycles = 5;
	while (cycles)
	{
		random_pop = rand() % 10;
		random_push = rand() % 10;
		// printf("\n");
		while (random_push--)
		{
			stack_push(stack, 0);
			// print_stack(stack->top);
		}
		// printf("\n");
		while (random_pop--)
		{
			stack_pop(stack);
			// print_stack(stack->top);
		}
		// printf("\n");
		--cycles;
	}
	stack_destroy(stack);
	return (PASS);
}

int test_stack_pop(void)
{
	test_print_verbose_start((char *) __FUNCTION__);
	test_print_verbose_test("test1", test1() == PASS);
	test_print_verbose_test("test2", test2() == PASS);
	test_print_verbose_test("test3", test3() == PASS);
	test_print_verbose_test("test4", test4() == PASS);
	test_print_verbose_end();
	return (1);
}
