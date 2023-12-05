/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_list_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 15:20:56 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/05 15:20:59 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../build/plib_test.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int comp(void *dt1, void *dt2)
{
	char *p1;
	char *p2;

	p1 = dt1;
	p2 = dt2;

	return (string_length(p1) <= string_length(p2));
}

void print_list(t_list *list)
{
	if (!list)
	{
		printf("\n");
		return;
	}
	printf("[%s]\n", (char *) list->data);
	print_list(list->next);
}

int test1(void)
{
	t_list *list;
	char  **split;
	char   *random_string;
	char   *set;
	int     i;

	set = string_to_boolset("abcdefhijklmnopqrstuvwxyz", (char[255]){0});
	random_string = string_random_custom(set, 4096);
	if (!random_string)
		return (0);
	split = string_split(random_string, 'a');
	i = 1;
	list = list_create(split[0]);
	while (split[i])
		list_insert_front(&list, split[i++]);
	// print_list(list);
	list_sort(&list, comp);
	// print_list(list);
	string_split_destroy(split, string_split_size(split));
	string_destroy(random_string);
	list_destroy(list);
	return (PASS);
}

int test_list_sort(void)
{
	test_print_verbose_start((char *) __FUNCTION__);
	test_print_verbose_test("test1", test1() == PASS);
	// test_print_verbose_test("test2", test2() == PASS);
	// test_print_verbose_test("test3", test3() == PASS);
	// test_print_verbose_test("test4", test4() == PASS);
	test_print_verbose_end();
	return (1);
}
