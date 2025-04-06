# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/02 21:34:27 by Pablo Escob       #+#    #+#              #
#    Updated: 2025/04/06 10:42:35 by Pablo Escob      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = netdata
LIB_NAME = lib$(NAME).a
TEST_NAME = test_$(NAME)

LIB_FT = ft
LIB_SPLITTER = splitter
LIB_STR_CH_DELETE = str_ch_delete
LIB_GET_APP_PATH = get_app_path
LIB_HANDLE_IN_FILE = handle_in_file

SRC_DIR = src
OBJ_DIR = objs
LIB_FT_DIR = ../libft
LIB_SPLITTER_DIR = ../splitter
LIB_STR_CH_DELETE_DIR = ../symb_str_delete
LIB_GET_APP_PATH_DIR = ../get_app_path
LIB_HANDLE_IN_FILE_DIR = ../handle_in_file

SRC = $(wildcard $(SRC_DIR)/*.c)
OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
TEST_FILE = test.c

LIB_FT_OBJS = $(LIB_FT_DIR)/$(OBJ_DIR)/*.o
LIB_SPLITTER_OBJS = $(LIB_SPLITTER_DIR)/$(OBJ_DIR)/*.o
LIB_STR_CH_DELETE_OBJS = $(LIB_STR_CH_DELETE_DIR)/$(OBJ_DIR)/*.o
LIB_GET_APP_PATH_OBJS = $(LIB_GET_APP_PATH_DIR)/$(OBJ_DIR)/*.o
LIB_HANDLE_IN_FILE_OBJS = $(LIB_HANDLE_IN_FILE_DIR)/$(OBJ_DIR)/*.o

CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIB_FT_FLAGS = -L$(LIBFT_DIR) -l$(LIBFT_NAME)
LIB_SPLITTER_F = -L$(LIB_SPLITTER_DIR) -l$(LIB_SPLITTER)
LIB_STR_CH_DELETE_F = -L$(LIB_STR_CH_DELETE_DIR) -l$(LIB_STR_CH_DELETE)
LIB_GET_APP_PATH_F = -L$(LIB_GET_APP_PATH_DIR) -l$(LIB_GET_APP_PATH)
LIB_HANDLE_IN_FILE_F = -L$(LIB_HANDLE_IN_FILE_DIR) -l$(LIB_HANDLE_IN_FILE)
READLINE_F = -lreadline
TEST_F = $(LIB_FT_FLAGS) $(LIB_SPLITTER_F) $(LIB_GET_APP_PATH_F) $(LIB_STR_CH_DELETE_F) $(LIB_HANDLE_IN_FILE_F) $(READLINE_F)

.PHONY: all, clean, fclean, re, lib, run

all: lib

lib: $(LIB_NAME)

clean:
	$(MAKE) -C $(LIB_FT_DIR) clean
	$(MAKE) -C $(LIB_SPLITTER_DIR) clean
	$(MAKE) -C $(LIB_STR_CH_DELETE_DIR) clean
	$(MAKE) -C $(LIB_GET_APP_PATH_DIR) clean
	$(MAKE) -C $(LIB_HANDLE_IN_FILE_DIR) clean
	rm -rf $(OBJ_DIR)

fclean: clean
	$(MAKE) -C $(LIB_FT_DIR) fclean
	$(MAKE) -C $(LIB_SPLITTER_DIR) fclean
	$(MAKE) -C $(LIB_STR_CH_DELETE_DIR) fclean
	$(MAKE) -C $(LIB_GET_APP_PATH_DIR) fclean
	$(MAKE) -C $(LIB_HANDLE_IN_FILE_DIR) fclean
	rm -f $(LIB_NAME) $(TEST_NAME)

re: fclean lib

run: lib
	$(MAKE) -C $(LIB_FT_DIR)
	$(MAKE) -C $(LIB_SPLITTER_DIR)
	$(MAKE) -C $(LIB_STR_CH_DELETE_DIR)
	$(MAKE) -C $(LIB_GET_APP_PATH_DIR)
	$(MAKE) -C $(LIB_HANDLE_IN_FILE_DIR)
	$(CC) $(CFLAGS) $(TEST_FILE) $(LIB_NAME) $(TEST_F) -o $(TEST_NAME)
	./$(TEST_NAME)

$(LIB_NAME): $(OBJ)
	ar -rc $@ $(OBJ)
	ranlib $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(OBJ_DIR)
	$(CC) -c $< -o $@