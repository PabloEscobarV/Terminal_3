# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/07 22:06:59 by Pablo Escob       #+#    #+#              #
#    Updated: 2025/04/07 22:38:27 by Pablo Escob      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = str_handler
LIB_NAME = lib$(NAME).a
TEST_NAME = test_$(NAME)

LIB_FT = ft
LIB_SPLITTER = splitter
LIB_STR_CH_DELETE = str_ch_delete
LIB_GET_APP_PATH = get_app_path
LIB_HANDLE_IN_FILE = handle_in_file
LIB_VAR_HANDLER = varhandler
LIB_HASH_TABLE = hashtable
LIB_NET_DATA = netdata

SRC_DIR = src
OBJ_DIR = objs
LIB_FT_DIR = ../libft
LIB_SPLITTER_DIR = ../splitter
LIB_STR_CH_DELETE_DIR = ../str_ch_delete
LIB_GET_APP_PATH_DIR = ../get_app_path
LIB_HANDLE_IN_FILE_DIR = ../handle_in_file
LIB_VAR_HANDLER_DIR = ../varhandler
LIB_HASH_TABLE_DIR = ../HashTable
LIB_NET_DATA_DIR = ../netdata

SRC = $(wildcard $(SRC_DIR)/*.c)
OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
TEST_FILE = test.c

CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIB_FT_FLAGS = -L$(LIBFT_DIR) -l$(LIBFT_NAME)
LIB_SPLITTER_F = -L$(LIB_SPLITTER_DIR) -l$(LIB_SPLITTER)
LIB_STR_CH_DELETE_F = -L$(LIB_STR_CH_DELETE_DIR) -l$(LIB_STR_CH_DELETE)
LIB_GET_APP_PATH_F = -L$(LIB_GET_APP_PATH_DIR) -l$(LIB_GET_APP_PATH)
LIB_HANDLE_IN_FILE_F = -L$(LIB_HANDLE_IN_FILE_DIR) -l$(LIB_HANDLE_IN_FILE)
LIB_VAR_HANDLER_F = -L$(LIB_VAR_HANDLER_DIR) -l$(LIB_VAR_HANDLER)
LIB_NET_DATA_F = -L$(LIB_NET_DATA_DIR) -l$(LIB_NET_DATA)
LIB_HASH_TABLE_F = -L$(LIB_HASH_TABLE_DIR) -l$(LIB_HASH_TABLE)
READLINE_F = -lreadline
TEST_F =	$(LIB_NET_DATA_F) \
					$(LIB_FT_FLAGS) \
					$(LIB_SPLITTER_F) \
					$(LIB_GET_APP_PATH_F) \
					$(LIB_STR_CH_DELETE_F) \
					$(LIB_HANDLE_IN_FILE_F) \
					$(LIB_VAR_HANDLER_F) \
					$(LIB_HASH_TABLE_F) \
					$(READLINE_F)
# TEST_F = $(LIB_FT_FLAGS) $(LIB_SPLITTER_F) $(LIB_GET_APP_PATH_F) $(LIB_STR_CH_DELETE_F) $(LIB_HANDLE_IN_FILE_F) $(LIB_HASH_TABLE_F) $(LIB_NET_DATA_F) $(READLINE_F)

.PHONY: all, clean, fclean, re, lib, run

all: lib

lib: $(LIB_NAME)

clean:
	$(MAKE) -C $(LIB_FT_DIR) clean
	$(MAKE) -C $(LIB_SPLITTER_DIR) clean
	$(MAKE) -C $(LIB_STR_CH_DELETE_DIR) clean
	$(MAKE) -C $(LIB_GET_APP_PATH_DIR) clean
	$(MAKE) -C $(LIB_HANDLE_IN_FILE_DIR) clean
	$(MAKE) -C $(LIB_NET_DATA_DIR) clean
	$(MAKE) -C $(LIB_HASH_TABLE_DIR) clean
	$(MAKE) -C $(LIB_VAR_HANDLER_DIR) clean
	rm -rf $(OBJ_DIR)

fclean: clean
	$(MAKE) -C $(LIB_FT_DIR) fclean
	$(MAKE) -C $(LIB_SPLITTER_DIR) fclean
	$(MAKE) -C $(LIB_STR_CH_DELETE_DIR) fclean
	$(MAKE) -C $(LIB_GET_APP_PATH_DIR) fclean
	$(MAKE) -C $(LIB_HANDLE_IN_FILE_DIR) fclean
	$(MAKE) -C $(LIB_NET_DATA_DIR) fclean
		$(MAKE) -C $(LIB_HASH_TABLE_DIR) fclean
	$(MAKE) -C $(LIB_VAR_HANDLER_DIR) fclean
	rm -f $(LIB_NAME) $(TEST_NAME)

re: fclean lib

run: lib
	$(MAKE) -C $(LIB_FT_DIR)
	$(MAKE) -C $(LIB_SPLITTER_DIR)
	$(MAKE) -C $(LIB_STR_CH_DELETE_DIR)
	$(MAKE) -C $(LIB_GET_APP_PATH_DIR)
	$(MAKE) -C $(LIB_HANDLE_IN_FILE_DIR)
	$(MAKE) -C $(LIB_NET_DATA_DIR)
	$(CC) $(CFLAGS) $(TEST_FILE) $(LIB_NAME) $(TEST_F) -o $(TEST_NAME)
	./$(TEST_NAME)

$(LIB_NAME): $(OBJ)
	ar -rc $@ $(OBJ)
	ranlib $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(OBJ_DIR)
	$(CC) -c $< -o $@