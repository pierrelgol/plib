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
# define PLIB_H

/******************************************************************************/
/*                                                                            */
/*                                Dependencies                                */
/*                                                                            */
/******************************************************************************/

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

/******************************************************************************/
/*                                                                            */
/*                                  String                                    */
/*                                                                            */
/******************************************************************************/

char					*string_create(unsigned int size);
char					*string_destroy(char *str);
int						string_compare(char *str1, char *str2);
int						string_ncompare(char *str1, char *str2, unsigned int n);
unsigned int			string_length(char *str);
char					*string_copy(char *dest, char *src, unsigned int n);
char					*string_concat(char *dest, char *src, unsigned int n);
char					*string_clone(char *str);
char					*string_reverse(char *str);
char					*string_slice(char *str, unsigned int start,
							unsigned int end);
char					*string_move(char *dst, char *src, unsigned int n);
char					*string_rotate(char *str, int shift);
char					*string_join(char *str1, char *str2);
char					*string_sort(char *str);
char					*string_pad(char *str, int ch, int left, int right);
char					*string_trim(char *str, int ch);
char					*string_set(char *str, int ch, unsigned int n);
char					*string_search(char *str1, char *sub);
unsigned int			string_count(char *str, int ch);
unsigned int			string_count_leading(char *str, int ch);
unsigned int			string_count_trailing(char *str, int ch);
long					string_to_long(char *str);

/******************************************************************************/
/*                                                                            */
/*                                  Split */
/*                                                                            */
/******************************************************************************/

char					**split(char *string, int ch);
char					**split_create(unsigned int size);
char					**split_destroy(char **split);
unsigned int			split_length(char **split);
unsigned int			split_size(char **split);
int						split_compare(char **split1, char **split2,
							unsigned int n);
char					**split_clone(char **split);
char					**split_reverse(char **split);
char					**split_slice(char **split, unsigned int start,
							unsigned int end);
char					**split_sort(char **split);
char					*split_search(char **split, char *string,
							int is_sorted);
char					*split_unsplit(char **split, int sep);
char					**split_whitespace(char *string);
char					**split_line(char *string);
char					**split_nsplit(char *string, unsigned int n);
char					**split_rotate(char **split, unsigned int n);

/******************************************************************************/
/*                                                                            */
/*                                  Char                                      */
/*                                                                            */
/******************************************************************************/

int						char_is_alnum(int ch);
int						char_is_alpha(int ch);
int						char_is_digit(int ch);
int						char_is_newline(int ch);
int						char_is_spaces(int ch);
int						char_is_whitespace(int ch);
int						char_is_lowercase(int ch);
int						char_is_uppercase(int ch);
int						char_is_even(int ch);
int						char_is_odd(int ch);
int						char_is_printable(int ch);
int						char_is_ascii(int ch);
int						char_is_binary(int ch);
int						char_is_hex(int ch);
int						char_is_octal(int ch);
int						char_is_decimal(int ch);
int						char_to_uppercase(int ch);
int						char_to_lowercase(int ch);
int						char_to_reversecase(int ch);

/******************************************************************************/
/*                                                                            */
/*                                  Memory                                    */
/*                                                                            */
/******************************************************************************/

void					*memory_create(unsigned int count, unsigned int size);
void					*memory_destroy(void *ptr);
int						memory_compare(void *m1, void *m2, unsigned int n);
void					*memory_copy(void *m1, void *m2, unsigned int n);
void					*memory_search(void *m1, int ch, unsigned int n);
void					*memory_move(void *m1, void *m2, unsigned int n);
void					*memory_set(void *m1, int ch, unsigned int n);

/******************************************************************************/
/*                                                                            */
/*                                  List                                      */
/*                                                                            */
/******************************************************************************/

struct					s_list
{
	struct s_list		*next;
	void				*data;
};

typedef struct s_list	t_list;

t_list					*list_create(void);
t_list					*list_destroy(t_list *self);
t_list					*list_insert_at(t_list **self, void *data,
							unsigned int index);
t_list					*list_pop_at(t_list **self, unsigned int index);
t_list					*list_push_at(t_list **self, t_list *node,
							unsigned int index);
t_list					*list_split_at(t_list **self, unsigned int index);
t_list					*list_clone(t_list **self);
t_list					*list_concat(t_list **dstl, t_list **srcl);
t_list					*list_rotate(t_list **list, int shift);
void					list_clear(t_list *list, unsigned int n);
void					*list_remove_at(t_list **self, unsigned int index);
void					*list_peek_at(t_list **self, unsigned int index);
void					list_sort(t_list **list, int (*f)(void *d1, void *d2));
unsigned int			list_length(t_list *list);

/******************************************************************************/
/*                                                                            */
/*                                  Stack                                     */
/*                                                                            */
/******************************************************************************/

typedef struct s_stack
{
	unsigned int		size;
	unsigned int		count;
	struct s_list		*top;
	struct s_list		*free_node;

}						t_stack;

t_stack					*stack_create(void);
t_stack					*stack_destroy(t_stack *self);
void					*stack_push(t_stack *self, void *data);
void					*stack_pop(t_stack *self);
void					*stack_peek(t_stack *self);
t_stack					*stack_grow(t_stack *self);
t_stack					*stack_shrink(t_stack *self);
void					stack_clear(t_stack *self);
unsigned int			stack_is_full(t_stack *self);
unsigned int			stack_is_empty(t_stack *self);
unsigned int			stack_length(t_stack *self);

/******************************************************************************/
/*                                                                            */
/*                                  iStack                                    */
/*                                                                            */
/******************************************************************************/

typedef struct s_istack
{
	int					count;
	int					capacity;
	int					*data;

}						t_istack;

t_istack				*istack_create(unsigned int size);
t_istack				*istack_destroy(t_istack *stack);
int						istack_is_empty(t_istack *stack);
int						istack_is_full(t_istack *stack);
int						istack_pop(t_istack *stack);
void					istack_push(t_istack *stack, int value);
void					istack_swap(t_istack *stack);
int						istack_peek_at(t_istack *stack, int index);
void					istack_rotate(t_istack *stack, int shift);
void					istack_rotate_left(t_istack *s, int shift);
void					istack_rotate_right(t_istack *s, int shift);
void					istack_print(t_istack *stack);

/******************************************************************************/
/*                                                                            */
/*                                  Bit                                       */
/*                                                                            */
/******************************************************************************/

unsigned int			bit_count_set_bits(unsigned int num);
unsigned int			bit_count_unset_bits(unsigned int num);
unsigned int			bit_rotate_left(unsigned int num, unsigned int shift);
unsigned int			bit_rotate_right(unsigned int num, unsigned int shift);
unsigned int			bit_set_bit(unsigned int num, unsigned int pos);
unsigned int			bit_toggle_bit(unsigned int num, unsigned int pos);
unsigned int			bit_unset_bit(unsigned int num, unsigned int pos);
unsigned int			bit_compare_bits(unsigned int num, unsigned int pos1,
							unsigned int pos2);
unsigned int			bit_swap_bits(unsigned int num, unsigned int pos1,
							unsigned int pos2, unsigned int nbits);
unsigned int			bit_reverse_bits(unsigned int num);
unsigned int			bit_check_parity(unsigned int num);
unsigned int			bit_is_set(unsigned int num, unsigned int pos);
unsigned int			bit_bitmask_create(unsigned int start,
							unsigned int end);
unsigned int			bit_bitmask_combine(unsigned int mask1,
							unsigned int mask2);

/******************************************************************************/
/*                                                                            */
/*                                  Table                                     */
/*                                                                            */
/******************************************************************************/

# ifndef DEFAULT_TABLE_SIZE
#  define DEFAULT_TABLE_SIZE 37781
# endif

typedef struct s_entry
{
	char				*key;
	void				*value;
}						t_entry;

typedef struct s_table
{
	unsigned int		size;
	unsigned int		capacity;
	t_entry				*body;
}						t_table;

t_table					*table_create(void);
void					table_destroy(t_table *self);
void					table_entry_set(t_table *self, char *key, void *value);
void					*table_entry_get(t_table *self, char *key);
unsigned long			table_hash(char *str);

t_entry					*table_body_create(unsigned int capacity);
void					table_body_remove(t_table *self, char *key);
void					table_body_resize(t_table *self, unsigned int capacity);
unsigned int			table_body_find_empty(t_table *self, char *key);

/******************************************************************************/
/*                                                                            */
/*                                  iTable                                    */
/*                                                                            */
/******************************************************************************/

typedef struct s_ientry
{
	char				*key;
	long				value;
}						t_ientry;

typedef struct s_itable
{
	unsigned int		size;
	unsigned int		capacity;
	t_ientry			*body;
}						t_itable;

t_itable				*itable_create(void);
void					itable_destroy(t_itable *self);
void					itable_entry_set(t_itable *self, char *key, long value);
long					itable_entry_get(t_itable *self, char *key);
unsigned long			itable_hash(char *str);

t_ientry				*itable_body_create(unsigned int capacity);
void					itable_body_remove(t_itable *self, char *key);
void					itable_body_resize(t_itable *self,
							unsigned int capacity);
unsigned int			itable_body_find_empty(t_itable *self, char *key);

/******************************************************************************/
/*                                                                            */
/*                                  File                                      */
/*                                                                            */
/******************************************************************************/

# define IS_OPEN 0
# define IS_VALID 1
# define READ_SIZE 4096

typedef struct s_file
{
	unsigned int		perm;
	unsigned int		flag;
	int					in;
	int					out;
	long				size;
	char				*path;
	char				*name;
	char				*content;

}						t_file;

t_file					*file_create(void);
t_file					*file_path_clone(t_file *file, char *path);
t_file					*file_name_clone(t_file *file, char *name);
t_file					*file_content_clone(t_file *file, char *content);
char					*file_content_search(t_file *file, char *sub);
char					**file_content_split(t_file *file, int ch);
int						file_open(char *path, int permissions);
int						file_read(int fd, char *buffer, unsigned int size);
int						file_write(int fd, char *buffer, unsigned int size);
int						file_size(char *path);
int						file_close(int fd);
t_file					*file_destroy(t_file *self);

#endif
