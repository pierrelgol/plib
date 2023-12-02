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

CC          := cc
RM          := rm -f
CFLAGS      := -g3 -Wall -Wextra -Werror


NAME        := ./build/libplibtest.a
SHARED_NAME := libplib.so

SRCS        := $(wildcard ./test_string/*.c) \
               $(wildcard ./test_memory/*.c) \
               $(wildcard ./test_char/*.c)

OBJS        := $(SRCS:.c=.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

so: $(OBJS)
	$(CC) $(CFLAGS) -shared -o $(SHARED_NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME) $(SHARED_NAME)

re: fclean all

