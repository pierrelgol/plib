# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/01 14:39:40 by plgol.perso       #+#    #+#              #
#    Updated: 2023/12/01 14:39:43 by plgol.perso      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC := cc
RM := rm -f
# CFLAGS =  -Wall 								\
# 		  -Wextra 								\
# 		  -glldb								\
# 		  -Weverything 							\
# 		  -fsanitize=address 					\
# 		  -fsanitize=undefined 					\
# 		  -fsanitize=integer					\
# 		  -fstrict-overflow						\

CFLAGS =  -Wall 								\
		  -Wextra 								\
		  -Werror 								\

NAME := libplib.a
SRC_DIRS := src/allocator	\
			src/bit 		\
			src/buffer 		\
			src/char 		\
			src/file 		\
			src/list 		\
			src/memory 		\
			src/print 		\
			src/split 		\
			sc/stack 		\
			src/string 		\
			src/table 		\

SRCS := $(foreach dir,$(SRC_DIRS),$(wildcard ./$(dir)/*.c))
OBJS := $(SRCS:.c=.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME) $(SHARED_NAME)

re: fclean all
