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

# include <errno.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef int			(*t_comparator)(void *, void *);

/* ------------------------- plib_list ------------------------- */

typedef struct s_list
{
	struct s_list	*next;
	void			*data;
}					t_list;

t_list				*plib_list_create(void *data);
void				plib_list_destroy(t_list **list);
void				plib_list_remove(t_list **list, t_list *node);
t_list				*plib_list_insert_after(t_list *node, void *data);
t_list				*plib_list_insert_front(t_list *list, void *data);
t_list				*plib_list_insert_back(t_list *list, void *data);
t_list				*plib_list_find_node(t_list *list, t_list *node);
t_list				*plib_list_find_data(t_list *list, void *data,
						t_comparator comp);

/* ------------------------- plib_table ------------------------ */

typedef struct s_entry
{
	char			*key;
	void			*value;
}					t_entry;

typedef struct s_table
{
	unsigned int	size;
	unsigned int	capacity;
	t_entry			*body;
}					t_table;

t_table				*plib_table_create(void);
void				plib_table_destroy(t_table *self);
void				plib_table_entry_set(t_table *self, char *key, void *value);
void				*plib_table_entry_get(t_table *self, char *key);
unsigned long		plib_table_hash(char *str);

t_entry				*plib_table_body_create(unsigned int capacity);
void				plib_table_body_remove(t_table *self, char *key);
void				plib_table_body_resize(t_table *self,
						unsigned int capacity);
unsigned int		plib_table_body_find_empty(t_table *self, char *key);

/* ------------------------- plib_string ----------------------- */

int					plib_string_compare(char *str1, char *str2,
						unsigned int cmpsize);
int					plib_string_concat(char *dst, char *str,
						unsigned int dstsize);
char				*plib_string_copy(char *dest, char *src,
						unsigned int cpysize);
char				*plib_string_duplicate(char *str);
char				*plib_string_find_first(char *str, int ch);
char				*plib_string_find_last(char *str, int ch);
char				*plib_string_join(char *str1, char *str2);
int					plib_string_length(char *str);
int					plib_string_index_of(char *str, int ch);
char				**plib_string_split(char *str, char *charset);
char				*plib_string_substring_create(char *str, int start,
						int length);
char				*plib_string_substring_find(char *str, char *sub,
						unsigned int srchsize);
int					plib_string_to_int(char *nbr);
char				*plib_string_to_lowercase(char *str);
char				*plib_string_to_upercase(char *str);
char				*plib_string_trim(char *str, char *charset);

/* ------------------------- plib_memory ----------------------- */

void				*plib_memory_alloc(unsigned int count, unsigned int size);
void				*plib_memory_dealloc(void *ptr);
void				*plib_memory_set(void *src, int ch, unsigned int setsize);
void				*plib_memory_find_first(void *src, int ch,
						unsigned int srchsize);
void				*plib_memory_find_last(void *src, int ch,
						unsigned int srchsize);
int					plib_memory_compare(void *src1, void *src2,
						unsigned int cmpsize);
void				*plib_memory_copy(void *dst, void *src,
						unsigned int cpysize);
void				*plib_memory_move(void *dst, void *src,
						unsigned int movsize);

/* ------------------------- plib_char ------------------------- */

int					plib_char_is_alpha(int ch);
int					plib_char_is_ascii(int ch);
int					plib_char_is_digit(int ch);
int					plib_char_is_lowercase(int ch);
int					plib_char_is_upercase(int ch);
int					plib_char_is_printable(int ch);
int					plib_char_is_space(int ch);
int					plib_char_is_alpha_numerical(int ch);
int					plib_char_is_in_range(int lbound, int ubound, int ch);
char				*plib_char_boolset_create(char *str);
char				*plib_char_boolset_create_from(char *empty_set, char *str);
char				*plib_char_boolset_destroy(char *set);
char				*plib_char_set_create(char *str);
char				*plib_char_set_create_from(char *empty_set, char *str);
char				*plib_char_set_destroy(char *set);

/* ------------------------- plib_writer ------------------------- */

typedef struct s_writer
{
	unsigned int	flags;
	int				fd;
	int				bsize;
	int				bcount;
	char			*buffer;

}					t_writer;

t_writer			*plib_writer_create(char *buffer, int size, int fd);
t_writer			*plib_writer_destroy(t_writer *self);
int					plib_writer_write(t_writer *self, int size);
int					plib_writer_write_until(t_writer *self, int delimiter);
int					plib_writer_flush(t_writer *self);

/* ------------------------- plib_reader ------------------------- */

typedef struct s_reader
{
	unsigned int	flags;
	int				fd;
	int				bsize;
	int				bcount;
	char			*buffer;

}					t_reader;

t_reader			*plib_reader_create(char *buffer, int size);
t_reader			*plib_reader_destroy(t_reader *self);
int					plib_reader_open(t_reader *self, char *path,
						unsigned int flags);
int					plib_reader_close(t_reader *self);
int					plib_reader_read(t_reader *self, int size);
int					plib_reader_read_until(t_reader *self, int delimiter);

void				ft_sort(void *data, size_t nel, size_t width,
						t_comparator comp);

#endif
