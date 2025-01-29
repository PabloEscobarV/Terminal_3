# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/29 22:10:30 by Pablo Escob       #+#    #+#              #
#    Updated: 2025/01/29 22:33:26 by Pablo Escob      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = get_app_path
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
CFLAGS = -Wall -Werror -Wextra
LIBFT_FLAGS = -L$(LIBFGT_DIR) -l$(LIB_NAME)
READLINE_FLAG = -lreadline

.PHONY: all, clean, fclean, re, lib, run

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
	ar -rc $@ $(OBJ) $(LIBFT_OBJ)
	ranlib $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(OBJ_DIR)
	$(CC) -c $< -o $@