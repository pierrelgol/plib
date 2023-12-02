#ifndef PLIB_TEST_H
#define PLIB_TEST_H

#include "../../plib.h"
#include <stdio.h>

#define FAIL 0
#define PASS 1
#define RESET "\033[0m"

#define BLACK "\033[0;30m"
#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define BLUE "\033[0;34m"
#define MAGENTA "\033[0;35m"
#define CYAN "\033[0;36m"
#define WHITE "\033[0;37m"

#define BOLDBLACK "\033[1;30m"
#define BOLDRED "\033[1;31m"
#define BOLDGREEN "\033[1;32m"
#define BOLDYELLOW "\033[1;33m"
#define BOLDBLUE "\033[1;34m"
#define BOLDMAGENTA "\033[1;35m"
#define BOLDCYAN "\033[1;36m"
#define BOLDWHITE "\033[1;37m"

void test_print_integer(char *name, int is_success, int value);
void test_print_verbose_start(char *name);
void test_print_verbose_test(char *name, int is_success);
void test_print_verbose_end(void);


int test_string_append_back(void);
int test_string_append_front(void);
int test_string_clone(void);
int test_string_compare(void);
int test_string_concat(void);
int test_string_contains(void);
int test_string_copy(void);
int test_string_count(void);
int test_string_create(void);
int test_string_destroy(void);
int test_string_destroy(void);
int test_string_ends_with(void);
int test_string_fill(void);
int test_string_filter(void);
int test_string_get_at(void);
int test_string_index_of(void);
int test_string_join(void);
int test_string_length(void);
int test_string_map_apply(void);
int test_string_map_assert(void);
int test_string_map_clone(void);
int test_string_map_count(void);
int test_string_map_filter(void);
int test_string_map_index_of(void);
int test_string_map_search(void);
int test_string_map_slice(void);
int test_string_nclone(void);
int test_string_ncompare(void);
int test_string_nconcat(void);
int test_string_ncopy(void);
int test_string_njoin(void);
int test_string_nlength(void);
int test_string_nsearch(void);
int test_string_nsplit(void);
int test_string_pad(void);
int test_string_pad_left(void);
int test_string_pad_right(void);
int test_string_search(void);
int test_string_search_replace(void);
int test_string_search_replace_all(void);
int test_string_string_set_at(void);
int test_string_string_set_at(void);
int test_string_shuffle(void);
int test_string_slice(void);
int test_string_sort(void);
int test_string_split(void);
int test_string_split_charset(void);
int test_string_split_create(void);
int test_string_split_destroy(void);
int test_string_split_map(void);
int test_string_start_with(void);
int test_string_to_boolset(void);
int test_string_to_freqset(void);
int test_string_to_int(void);
int test_string_to_long(void);
int test_string_to_uint(void);
int test_string_to_ulong(void);
int test_string_trim(void);
int test_string_trim_left(void);
int test_string_trim_right(void);
int test_string_trim_unsplit(void);

int test_char_is_alnum(void);
int test_char_is_alpha(void);
int test_char_is_digit(void);
int test_char_is_newline(void);
int test_char_is_spaces(void);
int test_char_is_whitespace(void);
int test_char_is_lowercase(void);
int test_char_is_uppercase(void);
int test_char_is_even(void);
int test_char_is_odd(void);
int test_char_is_printable(void);
int test_char_is_ascii(void);
int test_char_is_binary(void);
int test_char_is_hex(void);
int test_char_is_octal(void);
int test_char_is_decimal(void);

int test_char_to_uppercase(void);
int test_char_to_lowercase(void);
int test_char_to_reversecase(void);
int test_char_to_nextchar(void);
int test_char_to_prevchar(void);
int test_char_to_random(void);
int test_char_sort_ascending(void);
int test_char_sort_descending(void);

int test_memory_alloc(void);
int test_memory_dealloc(void);
int test_memory_compare(void);
int test_memory_copy(void);
int test_memory_clone(void);
int test_memory_search(void);
int test_memory_move(void);
int test_memory_set(void);

#endif
