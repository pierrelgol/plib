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

/******************************************************************************/
/*                                                                            */
/*                                Dependencies                                */
/*                                                                            */
/******************************************************************************/

#include <assert.h>
#include <fcntl.h>
#include <iso646.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>

/******************************************************************************/
/*                                                                            */
/*                                  Allocator                                 */
/*                                                                            */
/******************************************************************************/

#define LOG 0
#define FBA_ENOMEM "fba limit reached %d bytes wanted only %d bytes left\n"
struct s_allocator;
typedef unsigned char t_ressource;

typedef void *(t_fn_create) (struct s_allocator *self, size_t size);
typedef void *(t_fn_destroy) (struct s_allocator *self, void *ptr);
typedef void *(t_fn_realloc) (struct s_allocator *self, void *ptr, size_t prev, size_t next);
typedef int(t_fn_loger)(const char *fmt, ...);

typedef struct s_allocator
{
	size_t              capacity;
	size_t              count;
	bool                is_arena;
	bool                is_fba;
	bool                is_heap;
	bool                log_info;
	bool                log_verbose;
	t_fn_loger         *logger;
	t_ressource        *static_buffer;
	t_ressource        *heap_buffer;
	t_ressource        *region;
	t_fn_create        *create;
	t_fn_destroy       *destroy;
	t_fn_realloc       *realloc;
	struct s_list      *next;
	struct s_allocator *parent_allocator;

} t_allocator;

/* ********************************c_heapalloc******************************* */

struct s_allocator *heapalloc_init(void);
void               *heapalloc_deinit(struct s_allocator *self);
void               *heapalloc_destroy(struct s_allocator *self, void *ptr);
void               *heapalloc_create(struct s_allocator *self, size_t size);
void *heapalloc_realloc(struct s_allocator *self, void *ptr, size_t old_size, size_t size);

/* **********************************Arena*********************************** */

struct s_allocator *arena_init(struct s_allocator *parent_allocator, size_t size);
void *arena_deinit(struct s_allocator *self);
void *arena_destroy(struct s_allocator *self, void *ptr);
void *arena_create(struct s_allocator *self, size_t size);
void *arena_realloc(struct s_allocator *self, void *ptr, size_t old_size, size_t size);

/******************************************************************************/
/*                                                                            */
/*                                  String                                    */
/*                                                                            */
/******************************************************************************/

char        *string_create(struct s_allocator *allocator, size_t size);
char        *string_destroy(struct s_allocator *allocator, char *str);
int          string_compare(char *str1, char *str2);
int          string_ncompare(char *str1, char *str2, unsigned int n);
unsigned int string_length(char *str);
char        *string_copy(char *dest, char *src, unsigned int n);
char        *string_concat(char *dest, char *src, unsigned int n);
char        *string_clone(struct s_allocator *allocator, char *str);
char        *string_reverse(char *str);
char *string_slice(struct s_allocator *allocator, char *str, size_t start, size_t end);
char *string_move(char *dst, char *src, unsigned int n);
char *string_rotate(struct s_allocator *allocator, char *str, int shift);
char *string_join(struct s_allocator *allocator, char *str1, char *str2);
char *string_sort(char *str);
char *string_pad(struct s_allocator *allocator, char *str, int ch, size_t n);
char *string_trim(struct s_allocator *allocator, char *str, int ch);
char *string_set(char *str, int ch, unsigned int n);
char *string_search(char *string, char *pat, int slen, int plen);
unsigned int string_count(char *str, int ch);
unsigned int string_count_leading(char *str, int ch);
unsigned int string_count_trailing(char *str, int ch);
long         string_to_long(char *str);

/******************************************************************************/
/*                                                                            */
/*                                  Split */
/*                                                                            */
/******************************************************************************/

char       **split(struct s_allocator *allocator, char *string, int ch);
char       **split_create(struct s_allocator *allocator, unsigned int size);
char       **split_destroy(struct s_allocator *allocator, char **split);
unsigned int split_length(char **split);
unsigned int split_size(char **split);
int          split_compare(char **split1, char **split2, unsigned int n);
char       **split_clone(struct s_allocator *allocator, char **split);
char       **split_reverse(char **split);
char **split_slice(struct s_allocator *allocator, char **split, size_t start, size_t end);
char **split_sort(char **split);
char  *split_search(char **split, char *string, int is_sorted);
char  *split_unsplit(struct s_allocator *allocator, char **split, int sep);
char **split_whitespace(struct s_allocator *allocator, char *string);
char **split_line(struct s_allocator *allocator, char *string);
char **split_nsplit(struct s_allocator *allocator, char *string, unsigned int n);
char **split_rotate(struct s_allocator *allocator, char **split, unsigned int n);

/******************************************************************************/
/*                                                                            */
/*                                  Char                                      */
/*                                                                            */
/******************************************************************************/

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

/******************************************************************************/
/*                                                                            */
/*                                  Memory                                    */
/*                                                                            */
/******************************************************************************/

void *memory_create(unsigned int count, unsigned int size);
void *memory_realloc(void *ptr, size_t old_size, size_t size);
void *memory_destroy(void *ptr);
int   memory_compare(void *m1, void *m2, unsigned int n);
void *memory_copy(void *m1, void *m2, unsigned int n);
void *memory_search(void *m1, int ch, unsigned int n);
void *memory_move(void *m1, void *m2, unsigned int n);
void *memory_set(void *m1, int ch, unsigned int n);

/******************************************************************************/
/*                                                                            */
/*                                  List                                      */
/*                                                                            */
/******************************************************************************/

struct s_list
{
	struct s_list *next;
	void          *data;
};

typedef struct s_list t_list;

t_list *list_create(struct s_allocator *allocator);
t_list *list_destroy(struct s_allocator *allocator, t_list *self);
t_list *list_insert_at(struct s_allocator *allocator, t_list **self, void *data, unsigned int index);
t_list *list_pop_at(t_list **self, unsigned int index);
t_list *list_push_at(t_list **self, t_list *node, unsigned int index);
t_list *list_split_at(t_list **self, unsigned int index);
t_list *list_clone(struct s_allocator *allocator, t_list **self);
t_list *list_concat(t_list **dstl, t_list **srcl);
t_list *list_rotate(t_list **list, int shift);
void    list_clear(t_list *list, unsigned int n);
void *list_remove_at(struct s_allocator *allocator, t_list **self, unsigned int index);
void        *list_peek_at(t_list **self, unsigned int index);
void         list_sort(t_list **list, int (*f)(void *d1, void *d2));
unsigned int list_length(t_list *list);

/******************************************************************************/
/*                                                                            */
/*                                  Stack                                     */
/*                                                                            */
/******************************************************************************/

typedef struct s_stack
{
	unsigned int        size;
	unsigned int        count;
	struct s_list      *top;
	struct s_list      *free_node;
	struct s_allocator *allocator;
} t_stack;

t_stack     *stack_create(struct s_allocator *allocator);
t_stack     *stack_destroy(t_stack *self);
void        *stack_push(t_stack *self, void *data);
void        *stack_pop(t_stack *self);
void        *stack_peek(t_stack *self);
t_stack     *stack_grow(t_stack *self);
t_stack     *stack_shrink(t_stack *self);
void         stack_clear(t_stack *self);
unsigned int stack_is_full(t_stack *self);
unsigned int stack_is_empty(t_stack *self);
unsigned int stack_length(t_stack *self);

/******************************************************************************/
/*                                                                            */
/*                                  Bit                                       */
/*                                                                            */
/******************************************************************************/

unsigned int bit_count_set_bits(unsigned int num);
unsigned int bit_count_unset_bits(unsigned int num);
unsigned int bit_rotate_left(unsigned int num, unsigned int shift);
unsigned int bit_rotate_right(unsigned int num, unsigned int shift);
unsigned int bit_set_bit(unsigned int num, unsigned int pos);
unsigned int bit_toggle_bit(unsigned int num, unsigned int pos);
unsigned int bit_unset_bit(unsigned int num, unsigned int pos);
unsigned int bit_compare_bits(unsigned int num, unsigned int pos1, unsigned int pos2);
unsigned int bit_swap_bits(unsigned int num, unsigned int pos1, unsigned int pos2, unsigned int nbits);
unsigned int bit_reverse_bits(unsigned int num);
unsigned int bit_check_parity(unsigned int num);
unsigned int bit_is_set(unsigned int num, unsigned int pos);
unsigned int bit_bitmask_create(unsigned int start, unsigned int end);
unsigned int bit_bitmask_combine(unsigned int mask1, unsigned int mask2);

/******************************************************************************/
/*                                                                            */
/*                                  Table                                     */
/*                                                                            */
/******************************************************************************/

#ifndef DEFAULT_TABLE_SIZE
#define DEFAULT_TABLE_SIZE 37781
#endif

typedef struct s_entry
{
	char *key;
	void *value;
} t_entry;

typedef struct s_table
{
	unsigned int        size;
	unsigned int        capacity;
	t_entry            *body;
	struct s_allocator *allocator;
} t_table;

t_table      *table_create(struct s_allocator *allocator);
void          table_destroy(t_table *self);
void          table_entry_set(t_table *self, char *key, void *value);
void         *table_entry_get(t_table *self, char *key);
unsigned long table_hash(char *str);

t_entry *table_body_create(struct s_allocator *allocator, unsigned int capacity);
void         table_body_remove(t_table *self, char *key);
void         table_body_resize(t_table *self, unsigned int capacity);
unsigned int table_body_find_empty(t_table *self, char *key);

/******************************************************************************/
/*                                                                            */
/*                                  Buffer                                    */
/*                                                                            */
/******************************************************************************/

#define BUFFER_GROWTH_RATE 2
#define BUFFER_DEFAULT_CAPACITY 4095

typedef struct s_buffer
{
	int                 rindex;
	int                 count;
	int                 capacity;
	char               *data;
	struct s_allocator *allocator;

} t_buffer;

t_buffer *buffer_create(struct s_allocator *allocator);
t_buffer *buffer_destroy(t_buffer *buffer);
void      buffer_growth(t_buffer *buffer);
char      buffer_peek(t_buffer *buffer);
char     *buffer_ptr(t_buffer *buffer);
char      buffer_read(t_buffer *buffer);
void      buffer_should_grow(t_buffer *buffer, int size);
char      buffer_unread(t_buffer *buffer, char ch);
void      buffer_write(t_buffer *buffer, char ch);
void      buffer_reset(t_buffer *buffer);

/******************************************************************************/
/*                                                                            */
/*                                  File                                      */
/*                                                                            */
/******************************************************************************/

#define IS_OPEN 0
#define IS_VALID 1
#define READ_SIZE 1024

typedef struct s_file
{
	unsigned int        perm;
	unsigned int        flag;
	int                 in;
	int                 out;
	long                size;
	char               *path;
	char               *name;
	char               *content;
	t_buffer           *buffer;
	struct s_allocator *allocator;
} t_file;

t_file *file_create(struct s_allocator *allocator);
t_file *file_path_clone(t_file *file, char *path);
t_file *file_name_clone(t_file *file, char *name);
t_file *file_content_clone(t_file *file, char *content);
char   *file_content_search(t_file *file, char *sub);
char  **file_content_split(t_file *file, int ch);
int     file_buffer_create(t_file *file);
int     file_buffer_destroy(t_file *file);
int     file_buffer_read(t_file *file);
int     file_buffer_load_chunk(t_file *file, int chunk_size);
int     file_open(char *path, int permissions);
int     file_read(int fd, char *buffer, unsigned int size);
int     file_write(int fd, char *buffer, unsigned int size);
int     file_size(char *path);
int     file_close(int fd);
t_file *file_destroy(t_file *self);

/******************************************************************************/
/*                                                                            */
/*                                  Print				      */
/*                                                                            */
/******************************************************************************/

int print_string(int fd, char *string);
int print_string_nl(int fd, char *string);
int print_fmt(const char *fmt, ...);

enum e_state
{
	FSM_START,
	FSM_LOOK_FOR_FMT,
	FSM_FOUND_FMT_I8,
	FSM_FOUND_FMT_I32,
	FSM_FOUND_FMT_U32,
	FSM_FOUND_FMT_LHEX,
	FSM_FOUND_FMT_UHEX,
	FSM_FOUND_FMT_STR,
	FSM_FOUND_FMT_PTR,
	FSM_FOUND_FMT_PREC,
	FSM_PRINT_CHAR,
	FSM_STOP,
};

typedef enum e_state (*t_interpreter)(enum e_state state, int ch);
typedef int (*t_print_fmt)(va_list *arg);
typedef t_print_fmt (*t_dispatcher)(enum e_state state);

typedef struct s_fsm
{
	const char   *fmt;
	int           count;
	enum e_state  curr;
	t_interpreter get_curr_state;
	t_print_fmt   use_print_fmt;
	t_dispatcher  get_print_fmt;
} t_fsm;

t_fsm        fsm_init(const char *fmt);
enum e_state fsm_interpret(enum e_state prev, int ch);
t_print_fmt  fsm_dispatch(enum e_state curr);
int          fsm_eat_char(va_list *arg);
int          fsm_put_char(va_list *arg);
int          uputnbr_base(uint64_t num, char *base, int radix);
int          iputnbr_base(int64_t num, char *base, int radix);
int          print_fmt_i8(va_list *arg);
int          print_fmt_i32(va_list *arg);
int          print_fmt_u32(va_list *arg);
int          print_fmt_str(va_list *arg);
int          print_fmt_lhex(va_list *arg);
int          print_fmt_uhex(va_list *arg);
int          print_fmt_ptr(va_list *arg);

#endif
