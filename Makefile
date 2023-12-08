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

DEBUG_FLAGS := -Wall -Wextra -Wpedantic -Wundef -Wshadow -Wconversion -Wformat -g3 -O0 -std=c99 -march=native

RELEASE_FLAGS := -O2 -mcpu=native -flto

CFLAGS := $(DEBUG_FLAGS)

NAME := libplib.a
SHARED_NAME := libplib.so

SRC_DIRS := string memory char list bit stack table
SRCS := $(foreach dir,$(SRC_DIRS),$(wildcard ./$(dir)/*.c))
OBJS := $(SRCS:.c=.o)

.PHONY: all clean fclean re test

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

so: $(OBJS)
	$(CC) $(CFLAGS) -shared -o $(SHARED_NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME) $(SHARED_NAME) ./test/build/$(NAME)

re: fclean all

test: $(NAME)
	@echo "Running test..."
	@cp libplib.a ./test/build/
	@cp plib.h ./test/build/
	@cd ./test/ && sh build_test.sh

debug: CFLAGS := $(DEBUG_FLAGS)
debug: all
	@echo "Switched to Debug mode: $(CFLAGS)"

release: CFLAGS := $(RELEASE_FLAGS)
release: all
	@echo "Switched to Release mode: $(CFLAGS)"
