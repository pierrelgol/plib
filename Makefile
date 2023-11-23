# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/12 16:10:27 by plgol.perso       #+#    #+#              #
#    Updated: 2023/11/12 16:10:28 by plgol.perso      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC         = cc
RM         = rm -f
CFLAGS     = -Wall -Wextra -Werror -fPIC -g3
NAME       = libplib.a
SHARED_NAME= libplib.so

SRCS       =  ./plib_char/plib_char_boolset_create.c		\
			  ./plib_char/plib_char_boolset_create_from.c	\
			  ./plib_char/plib_char_boolset_destroy.c		\
			  ./plib_char/plib_char_is_alpha.c				\
			  ./plib_char/plib_char_is_alpha_numerical.c	\
			  ./plib_char/plib_char_is_ascii.c				\
			  ./plib_char/plib_char_is_digit.c				\
			  ./plib_char/plib_char_is_in_range.c			\
			  ./plib_char/plib_char_is_lowercase.c			\
			  ./plib_char/plib_char_is_printable.c			\
			  ./plib_char/plib_char_is_space.c				\
			  ./plib_char/plib_char_is_upercase.c			\
			  ./plib_char/plib_char_set_create.c			\
			  ./plib_char/plib_char_set_create_from.c		\
			  ./plib_char/plib_char_set_destroy.c			\
															\
			  ./plib_list/plib_list_create.c				\
			  ./plib_list/plib_list_destroy.c				\
			  ./plib_list/plib_list_find_data.c				\
			  ./plib_list/plib_list_find_node.c				\
			  ./plib_list/plib_list_insert_after.c			\
			  ./plib_list/plib_list_insert_back.c			\
			  ./plib_list/plib_list_insert_front.c			\
			  ./plib_list/plib_list_remove.c				\
															\
			  ./plib_memory/plib_memory_alloc.c				\
			  ./plib_memory/plib_memory_compare.c			\
			  ./plib_memory/plib_memory_copy.c				\
			  ./plib_memory/plib_memory_dealloc.c			\
			  ./plib_memory/plib_memory_find_first.c		\
			  ./plib_memory/plib_memory_find_last.c			\
			  ./plib_memory/plib_memory_move.c				\
			  ./plib_memory/plib_memory_set.c				\
															\
			  ./plib_reader/plib_reader_close.c				\
			  ./plib_reader/plib_reader_create.c			\
			  ./plib_reader/plib_reader_destroy.c			\
			  ./plib_reader/plib_reader_open.c				\
			  ./plib_reader/plib_reader_read.c				\
			  ./plib_reader/plib_reader_read_until.c		\
															\
			  ./plib_string/plib_string_compare.c			\
			  ./plib_string/plib_string_concat.c			\
			  ./plib_string/plib_string_copy.c				\
			  ./plib_string/plib_string_duplicate.c			\
			  ./plib_string/plib_string_find_first.c		\
			  ./plib_string/plib_string_find_last.c			\
			  ./plib_string/plib_string_index_of.c			\
			  ./plib_string/plib_string_join.c				\
			  ./plib_string/plib_string_length.c			\
			  ./plib_string/plib_string_split.c				\
			  ./plib_string/plib_string_substring_create.c	\
			  ./plib_string/plib_string_substring_find.c	\
			  ./plib_string/plib_string_to_int.c			\
			  ./plib_string/plib_string_to_lowercase.c		\
			  ./plib_string/plib_string_to_upercase.c		\
			  ./plib_string/plib_string_trim.c				\
															\
			  ./plib_table/plib_table_body_create.c			\
			  ./plib_table/plib_table_body_find_empty.c		\
			  ./plib_table/plib_table_body_remove.c			\
			  ./plib_table/plib_table_body_resize.c			\
			  ./plib_table/plib_table_create.c				\
			  ./plib_table/plib_table_destroy.c				\
			  ./plib_table/plib_table_entry_get.c			\
			  ./plib_table/plib_table_entry_set.c			\
			  ./plib_table/plib_table_hash.c				\
															\
			  ./plib_writer/plib_writer_create.c			\
			  ./plib_writer/plib_writer_destroy.c			\
			  ./plib_writer/plib_writer_flush.c				\
			  ./plib_writer/plib_writer_write.c				\
			  ./plib_writer/plib_writer_write_until.c		

OBJS       = $(SRCS:.c=.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

so: $(OBJS)
	$(CC) $(CLFAGS) -shared -o $(SHARED_NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME) $(SHARED_NAME)

re: fclean all
