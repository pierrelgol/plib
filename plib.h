/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plib.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:47:10 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/11/21 15:47:11 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLIB_H
#define PLIB_H

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <stdio.h>

// Initialize a static char array with ASCII values
static const char asciiTable[129] = {
    '\0',   '\x01', '\x02', '\x03', '\x04', '\x05', '\x06', '\x07', '\x08',
    '\t',   '\n',   '\x0b', '\x0c', '\r',   '\x0e', '\x0f', '\x10', '\x11',
    '\x12', '\x13', '\x14', '\x15', '\x16', '\x17', '\x18', '\x19', '\x1a',
    '\x1b', '\x1c', '\x1d', '\x1e', '\x1f', ' ',    '!',    '"',    '#',
    '$',    '%',    '&',    '\'',   '(',    ')',    '*',    '+',    ',',
    '-',    '.',    '/',    '0',    '1',    '2',    '3',    '4',    '5',
    '6',    '7',    '8',    '9',    ':',    ';',    '<',    '=',    '>',
    '?',    '@',    'A',    'B',    'C',    'D',    'E',    'F',    'G',
    'H',    'I',    'J',    'K',    'L',    'M',    'N',    'O',    'P',
    'Q',    'R',    'S',    'T',    'U',    'V',    'W',    'X',    'Y',
    'Z',    '[',    '\\',   ']',    '^',    '_',    '`',    'a',    'b',
    'c',    'd',    'e',    'f',    'g',    'h',    'i',    'j',    'k',
    'l',    'm',    'n',    'o',    'p',    'q',    'r',    's',    't',
    'u',    'v',    'w',    'x',    'y',    'z',    '{',    '|',    '}',
    '~',    '\x7f'};

/*############################################################################*/
/*                                [PlibString] */
/*############################################################################*/

char         *string_append_back(char *str1, char *str2);
char         *string_append_front(char *str1, char *str2);
char         *string_clone(char *str);
int           string_compare(char *str1, char *str2);
int           string_concat(char *dst, char *src);
int           string_contains(char *str, char *substring);
char         *string_copy(char *dst, char *src);
int           string_count(char *dst, int ch);
char         *string_create(unsigned int size);
char         *string_destroy(char *str);
int           string_ends_with(char *str, char *sufix);
char         *string_fill(char *dst, int ch);
char         *string_filter(char *str, int ch);
int           string_get_at(char *str, unsigned int index);
int           string_index_of(char *str, int ch);
char         *string_join(char *str1, char *str2);
unsigned int  string_length(char *str);
int           string_map_assert(char *str, int (*f)(int ch));
char         *string_map_apply(char *str, int (*f)(int ch));
char         *string_map_clone(char *str, int (*f)(int ch));
int           string_map_count(char *str, int (*f)(int ch));
char         *string_map_filter(char *str, int (*f)(int ch));
int           string_map_index_of(char *str, int (*f)(int ch));
char         *string_map_search(char *str, int (*f)(int ch));
char         *string_map_slice(char *str, int (*f)(int ch));
char         *string_nclone(char *src, unsigned int n);
int           string_ncompare(char *str1, char *str2, unsigned int n);
int           string_nconcat(char *dst, char *src, unsigned int n);
char         *string_ncopy(char *dst, char *src, unsigned int n);
char         *string_njoin(char *str1, char *str2, unsigned int n);
char         *string_nsearch(char *str, char *sub, unsigned int n);
char         *string_pad(char *str, int ch, unsigned int n);
char         *string_pad_left(char *str, int ch, unsigned int n);
char         *string_pad_right(char *str, int ch, unsigned int n);
char         *string_random(unsigned int n);
char         *string_random_custom(char *set, unsigned int n);
char         *string_strip_back(char *str1, char *str2);
char         *string_strip_front(char *str1, char *str2);
char         *string_reverse(char *str);
char         *string_rotate_left(char *str, unsigned int n);
char         *string_rotate_right(char *str, unsigned int n);
char         *string_search(char *str, char *sub);
char         *string_search_replace(char *str, char *sub, char *with);
char         *string_search_replace_all(char *str, char *sub, char *with);
int           string_set_at(char *str, unsigned int index, int ch);
char         *string_shuffle(char *str);
char         *string_slice(char *str1, unsigned int start, unsigned int end);
char         *string_sort(char *str, int (*f)(int ch1, int ch2));
int           string_starts_with(char *str, char *prefix);
char         *string_to_boolset(char *str, char set[255]);
char         *string_to_freqset(char *str, char set[255]);
int           string_to_int(char *str);
long          string_to_long(char *str);
unsigned int  string_to_uint(char *str);
unsigned long string_to_ulong(char *str);
char         *string_trim(char *str, int ch);
char         *string_trim_left(char *str, int ch);
char         *string_trim_right(char *str, int ch);

char       **string_split_create(unsigned int n);
char       **string_split_destroy(char **str, unsigned int n);
char       **string_split(char *str, int ch);
char        *string_split_join(char **strs, int ch);
unsigned int string_split_length(char **strs);
unsigned int string_split_size(char **strs);
char       **string_split_clone(char **strs);

char **string_split_map_set(char *str, char set[255]);
int    string_split_map_assert(char *str, int (*f)(int ch));
char **string_split_map_apply(char *str, int (*f)(int ch));
int    string_split_compare(char **strs1, char **strs2);
char **string_split_map_clone(char *str, int (*f)(int ch));
int    string_split_map_count(char *str, int (*f)(int ch));
char **string_split_map_filter(char *str, int (*f)(int ch));
int    string_split_map_index_of(char *str, int (*f)(int ch));
char **string_split_map_search(char *str, int (*f)(int ch));
char **string_split_map_slice(char *str, int (*f)(int ch));

/*############################################################################*/
/*                                [PlibChar]                                  */
/*############################################################################*/

int char_is_alnum(int ch);
int char_is_alpha(int ch);
int char_is_digit(int ch);
int char_is_newline(int ch);
int char_is_spaces(int ch);
int char_is_whitespace(int ch);
int char_is_lowercase(int ch);
int char_is_uppercase(int ch);
int char_is_even(int ch);
int char_is_odd(int ch);
int char_is_printable(int ch);
int char_is_ascii(int ch);
int char_is_binary(int ch);
int char_is_hex(int ch);
int char_is_octal(int ch);
int char_is_decimal(int ch);

int char_to_uppercase(int ch);
int char_to_lowercase(int ch);
int char_to_reversecase(int ch);
int char_to_nextchar(int ch);
int char_to_prevchar(int ch);
int char_to_random(int ch);
int char_sort_ascending(int ch1, int ch2);
int char_sort_descending(int ch1, int ch2);

/*############################################################################*/
/*                                [PlibMemory]                                */
/*############################################################################*/

void *memory_alloc(unsigned int count, unsigned int size);
void *memory_dealloc(void *ptr);
int   memory_compare(void *m1, void *m2, unsigned int n);
void *memory_copy(void *m1, void *m2, unsigned int n);
void *memory_clone(void *m1, unsigned int n);
void *memory_search(void *m1, int ch, unsigned int n);
void *memory_move(void *m1, const void *m2, unsigned int n);
void *memory_set(void *m1, int ch, unsigned int n);

/*############################################################################*/
/*                                [PlibdList] */
/*############################################################################*/

struct s_list
{
	struct s_list *next;
	void          *data;
};

typedef struct s_list t_list;

t_list      *list_create(void *data);
t_list      *list_destroy(t_list *self);
t_list	    *list_insert_at(t_list **self, void *data, unsigned int index);
void	    *list_remove_at(t_list **self, unsigned int index);
t_list      *list_insert_front(t_list **self, void *data);
t_list      *list_insert_back(t_list **self, void *data);
void        *list_remove_front(t_list **self);
void	    *list_remove_at(t_list **self, unsigned int index);
void        *list_remove_back(t_list **self);
unsigned int list_length(t_list *list);

/*############################################################################*/
/*                                [PROTOTYPES] */
/*############################################################################*/

// needs a lot of improvent on the split functions turns out they are more important then you might think
// we need more higher level function to transform a split progressively, mroe filter more mapping matching etc.

char *string_search_first(char *str, char *sub);
char *string_search_last(char *str, char *sub);
char *string_map_match_first(char *str, char *(*f)(char *src));
char *string_map_match_last(char *str, char *(*f)(char *src));

#endif
