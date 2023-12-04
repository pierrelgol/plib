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
# CFLAGS      := -Wall -Wextra  -Wpedantic -Wundef -Wshadow -Wconversion -Wformat \
#                -g -O0 -fsanitize=address -fsanitize=undefined \
#                -std=c99 -march=native -pg -fprofile-instr-generate -fcoverage-mapping


NAME        := libplib.a
SHARED_NAME := libplib.so

SRCS        := $(wildcard ./string/*.c) \
               $(wildcard ./memory/*.c) \
               $(wildcard ./char/*.c)   \
               $(wildcard ./list/*.c) 

OBJS        := $(SRCS:.c=.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS) && cp libplib.a ./test/build/libplib.a && cd ./test/ && sh build_test.sh

so: $(OBJS)
	$(CC) $(CFLAGS) -shared -o $(SHARED_NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME) $(SHARED_NAME)

re: fclean all

