/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 11:47:20 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/02 11:47:22 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "plib_test.h"
#include <stdio.h>


void test_print_verbose_start(char *name)
{
	printf("%s%-32s%s : ", BLUE, name, RESET);
}

void test_print_verbose_test(char *name, int is_success)
{
	(void)name;
	if (is_success)
	{
		printf("%s%4s%s",GREEN, "[OK]", RESET);
	}
	else
		printf("%s%5s%s",RED, "[KO]", RESET);
}
// void test_print_verbose_test(char *name, int is_success)
// {
// 	(void)name;
// 	if (is_success)
// 	{
// 		printf("[%s%s%s][%s%s%s]",BLUE ,name, RESET, GREEN, "Pass", RESET);
// 	}
// 	else
// 		printf("[%s%s%s][%s%s%s]",BLUE ,name, RESET, RED, "Fail", RESET);
// }
void test_print_verbose_end(void)
{
	printf("\n");
}

int main(void)
{
	printf("\n##############################[PlibChar]##############################\n");
	test_char_is_alnum();
	test_char_is_alpha();
	test_char_is_digit();
	test_char_is_newline();
	test_char_is_spaces();
	test_char_is_whitespace();
	test_char_is_lowercase();
	test_char_is_uppercase();
	test_char_is_even();
	test_char_is_odd();
	test_char_is_printable();
	test_char_is_ascii();
	test_char_is_binary();
	test_char_is_hex();
	test_char_is_octal();
	test_char_is_decimal();
	test_char_to_uppercase();
	test_char_to_lowercase();
	test_char_to_reversecase();
	test_char_to_nextchar();
	test_char_to_prevchar();
	test_char_to_random();
	test_char_sort_ascending();
	test_char_sort_descending();
	printf("\n##############################[PlibMemory]############################\n");
	test_memory_alloc();
	test_memory_clone();
	test_memory_compare();
	test_memory_copy();
	test_memory_dealloc();
	test_memory_set();
	test_memory_search();
	test_memory_move();
	printf("\n##############################[PlibString]############################\n");
	test_string_append_back();
	test_string_append_front();
	test_string_clone();
	test_string_compare();
	test_string_concat();
	test_string_contains();
	test_string_copy();
	test_string_search();
	test_string_count();
	test_string_create();
	test_string_destroy();
	test_string_ends_with();
	test_string_fill();
	test_string_filter();
	test_string_get_at();
	test_string_index_of();
	test_string_join();
	test_string_length();
	test_string_map_apply();
	test_string_map_clone();
	test_string_map_count();
	test_string_map_filter();
	test_string_map_index_of();
	test_string_map_search();
	test_string_map_assert();
	test_string_map_slice();
	printf("\n######################################################################\n");
	// test_string_nclone();
	// test_string_ncompare();
	// test_string_nconcat();
	// test_string_ncopy();
	// test_string_njoin();
	// test_string_nlength();
	// test_string_nsearch();
	// test_string_nsplit();
	// test_string_pad();
	// test_string_pad_left();
	// test_string_pad_right();
	// test_string_search_replace();
	// test_string_search_replace_all();
	// test_string_string_set_at();
	// test_string_string_set_at();
	// test_string_shuffle();
	// test_string_slice();
	// test_string_sort();
	// test_string_split();
	// test_string_split_charset();
	// test_string_split_create();
	// test_string_split_destroy();
	// test_string_split_map();
	// test_string_start_with();
	// test_string_to_boolset();
	// test_string_to_freqset();
	// test_string_to_int();
	// test_string_to_long();
	// test_string_to_uint();
	// test_string_to_ulong();
	// test_string_trim();
	// test_string_trim_left();
	// test_string_trim_right();
	// test_string_trim_unsplit();
}
