# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: black <black@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/11 15:51:17 by black             #+#    #+#              #
#    Updated: 2024/11/11 16:27:43 by black            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = splitter
LIB_NAME = lib$(NAME).a
TEST_NAME = test_$(NAME)
LIBFT_NAME = ft

SRC_DIR = src
OBJ_DIR = objs
LIBFT_DIR = ../libft

SRC = $(wildcard $(SRC_DIR)/*.c)
OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
TEST_FILE = test.c

LIBFT_OBJ = $(LIBFT_DIR)/$(OBJ_DIR)/*.o

CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIBFT_FLAGS = -L$(LIBFT_DIR) -l$(LIBFT_NAME)
READLINE_FLAG = -lreadline

.PHONY: all, clean, fclnean, re, lib, run

all: lib

lib: $(LIB_NAME)

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -rf $(OBJ_DIR)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
		rm -f $(TEST_NAME) $(LIB_NAME)

re: fclean lib

run: lib
	$(CC) $(CFLAGS) $(TEST_FILE) -L. -l$(NAME) $(READLINE_FLAG) -o $(TEST_NAME)
	./$(TEST_NAME)

$(LIB_NAME): $(OBJ)
	$(MAKE) -C $(LIBFT_DIR)
	ar -rc $@ $(OBJ) $(LIBFT_DIR)/$(OBJ_DIR)/*.o
	ranlib $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(OBJ_DIR)
	$(CC) -c -g $< -o $@
