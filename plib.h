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

#include <errno.h>
#include <fcntl.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define ALOWE "abcdefhijklmnopqrstuvwxyz"
#define AUPER "ABCDEFHIJKLMNOPQRSTUVWXYZ"
#define ALPHA "abcdefhijklmnopqrstuvwxyzABCDEFHIJKLMNOPQRSTUVWXYZ"
#define ALNUM "abcdefhijklmnopqrstuvwxyzABCDEFHIJKLMNOPQRSTUVWXYZ0123456789"
#define DIGIT "0123456789"

typedef int (*t_comparator)(void *, void *);

/* ------------------------- plib_list ------------------------- */

typedef struct s_list
{
	struct s_list *next;
	void          *data;
} t_list;

t_list *plib_list_create(void *data);
void    plib_list_destroy(t_list **list);
void    plib_list_remove(t_list **list, t_list *node);
t_list *plib_list_insert_after(t_list *node, void *data);
t_list *plib_list_insert_front(t_list *list, void *data);
t_list *plib_list_insert_back(t_list *list, void *data);
t_list *plib_list_find_node(t_list *list, t_list *node);
t_list *plib_list_find_data(t_list *list, void *data, t_comparator comp);

/* ------------------------- plib_table ------------------------ */

typedef struct s_entry
{
	char *key;
	void *value;
} t_entry;

typedef struct s_table
{
	unsigned int size;
	unsigned int capacity;
	t_entry     *body;
} t_table;

t_table      *plib_table_create(void);
void          plib_table_destroy(t_table *self);
void          plib_table_entry_set(t_table *self, char *key, void *value);
void         *plib_table_entry_get(t_table *self, char *key);
unsigned long plib_table_hash(char *str);

t_entry     *plib_table_body_create(unsigned int capacity);
void         plib_table_body_remove(t_table *self, char *key);
void         plib_table_body_resize(t_table *self, unsigned int capacity);
unsigned int plib_table_body_find_empty(t_table *self, char *key);

/* ------------------------- plib_string ----------------------- */

int    plib_string_compare(char *str1, char *str2);
int    plib_string_compare_until(char *str1, char *str2, unsigned int cmpsize);
int    plib_string_concat(char *dst, char *str);
char  *plib_string_copy(char *dest, char *src, unsigned int cpysize);
char  *plib_string_duplicate(char *str);
char  *plib_string_find_first(char *str, int ch);
char  *plib_string_find_last(char *str, int ch);
char  *plib_string_join(char *str1, char *str2);
int    plib_string_length(char *str);
int    plib_string_index_of(char *str, int ch);
char **plib_string_split(char *str, char *charset);
char  *plib_string_substring_create(char *str, int start, int length);
char  *plib_string_substring_find(char *str, char *sub, unsigned int bound);
int    plib_string_to_int(char *nbr);
char  *plib_string_to_lowercase(char *str);
char  *plib_string_to_upercase(char *str);
char  *plib_string_trim(char *str, char *charset);

/* ------------------------- plib_memory ----------------------- */

void *plib_memory_alloc(unsigned int count, unsigned int size);
void *plib_memory_dealloc(void *ptr);
void *plib_memory_set(void *src, int ch, unsigned int setsize);
void *plib_memory_find_first(void *src, int ch, unsigned int srchsize);
void *plib_memory_find_last(void *src, int ch, unsigned int srchsize);
int   plib_memory_compare(void *src1, void *src2, unsigned int cmpsize);
void *plib_memory_copy(void *dst, void *src, unsigned int cpysize);
void *plib_memory_move(void *dst, void *src, unsigned int movsize);

/* ------------------------- plib_char ------------------------- */

int   plib_char_is_alpha(int ch);
int   plib_char_is_ascii(int ch);
int   plib_char_is_digit(int ch);
int   plib_char_is_lowercase(int ch);
int   plib_char_is_upercase(int ch);
int   plib_char_is_printable(int ch);
int   plib_char_is_space(int ch);
int   plib_char_is_alpha_numerical(int ch);
int   plib_char_is_in_range(int lbound, int ubound, int ch);
char *plib_char_boolset_create(char *str);
char *plib_char_boolset_create_from(char *empty_set, char *str);
char *plib_char_boolset_destroy(char *set);
char *plib_char_set_create(char *str);
char *plib_char_set_create_from(char *empty_set, char *str);
char *plib_char_set_destroy(char *set);

/* ------------------------- plib_testing ------------------------- */

int   plib_testing_assert_memory_eq(void *m1, void *m2, int n, char *name);
int   plib_testing_assert_string_eq(char *str1, char *str2, char *name);
char *plib_testing_string_generator(char *set, int length);
char *plib_testing_fstring_generator(char *around, char *inside, int size);
int   plib_testing_assert_condition(int condition, char *name);

/* ------------------------- plib_misc ------------------------- */

void plib_insertion_sort(void *data, size_t nel, size_t width, t_comparator comp);
float        plib_fast_square_root(float number);
unsigned int plib_fast_random_int(unsigned int index);

/* ------------------------- plib_IO ------------------------- */

#define TYPE_FILE 0x1
#define TYPE_FD 0x2
#define IS_OPEN 0x4
#define IS_VALID 0x8
#define IS_EOF 0x16
#define IS_FREEABLE_BUFFER 0x32

struct s_file
{
	long int     size;
	long int     count;
	int          fd;
	unsigned int perm;
	unsigned int status;
	char        *path;
	char        *content;
};

typedef struct s_file t_file;

int     plib_io_file_close(t_file *self);
int     plib_io_file_open(t_file *self, char *path, int perm);
int     plib_io_file_read(t_file *self, int rbyte, int fd);
int     plib_io_file_write(t_file *self, int rbyte, int fd);
int     plib_io_file_attach_buffer(t_file *self, char *buffer, int bsize);
int     plib_io_file_create_buffer(t_file *self, int rsize);
t_file *plib_io_file_copy(t_file *self);
t_file *plib_io_file_create(int status);
t_file *plib_io_file_destroy(t_file *self);

t_file *plib_io_file_erase_content(t_file *self);
char  **plib_io_file_split_token(t_file *self, char *charset);
char  **plib_io_file_split_chunk(t_file *self, int chunk_size);
t_list *plib_io_file_split_list_chunk(t_file *self, int chunk_size);

/* ------------------------- plib_allocators ------------------------- */

struct s_bmp_alloc
{
	unsigned long count;
	unsigned long size;
	void         *memory;
};

typedef struct s_bmp_alloc t_bmp_alloc;

t_bmp_alloc *plib_bump_alloc_create(unsigned long count, unsigned long size);
void *plib_bump_alloc_alloc(t_bmp_alloc *self, unsigned long count, unsigned long size);
void *plib_bump_alloc_dealloc(t_bmp_alloc *self, void *ptr);
void *plib_bump_alloc_destroy(t_bmp_alloc *self);

typedef struct s_pool
{
	t_list *memory_list;

} t_pool;

t_pool *plib_allocators_pool_create(unsigned long npool, unsigned long pool_size);

void *plib_allocators_pool_alloc(t_pool *self);
void  plib_allocators_pool_dealloc(t_pool *self, void *ptr);

/* ------------------------- plib_bit ------------------------- */

unsigned int plib_bit_count_set_bits(unsigned int num);
unsigned int plib_bit_count_unset_bits(unsigned int num);
unsigned int plib_bit_rotate_left(unsigned int num, unsigned int shift);
unsigned int plib_bit_rotate_right(unsigned int num, unsigned int shift);
unsigned int plib_bit_set_bit(unsigned int num, unsigned int pos);
unsigned int plib_bit_toggle_bit(unsigned int num, unsigned int pos);
unsigned int plib_bit_unset_bit(unsigned int num, unsigned int pos);
unsigned int plib_bit_compare_bits(unsigned int num, unsigned int pos1, unsigned int pos2);
unsigned int plib_bit_swap_bits(unsigned int num, unsigned int pos1, unsigned int pos2, unsigned int nbits);
unsigned int plib_bit_reverse_bits(unsigned int num);
unsigned int plib_bit_check_parity(unsigned int num);
unsigned int plib_bit_is_set(unsigned int num, unsigned int pos);
unsigned int plib_bit_bitmask_create(unsigned int start, unsigned int end);
unsigned int plib_bit_bitmask_combine(unsigned int mask1, unsigned int mask2);

/* ------------------------- plib_bitset ------------------------- */

#endif
