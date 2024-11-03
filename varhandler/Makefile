# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/30 21:43:28 by Pablo Escob       #+#    #+#              #
#    Updated: 2024/09/30 22:00:12 by Pablo Escob      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = varhandler
LIBNAME = lib$(NAME).a

TESTNAME = test
TESTFILE = test.c

HASHTABLE = hashtable
LIBFT = ft

SRCDIR = src
OBJDIR = objs

HASHTABLEDIR = ../HashTable
LIBFTDIR = ../libft

SRC = $(wildcard $(SRCDIR)/*.c)
OBJ = $(SRC:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror

.PHONY: all, lib, run, re, clean, fclean

all: lib

lib: $(LIBNAME)

clean:
	$(MAKE) -C $(HASHTABLEDIR) clean
	$(MAKE) -C $(LIBFTDIR) clean
	rm -rf $(OBJDIR)

fclean: clean
	$(MAKE) -C $(HASHTABLEDIR) fclean
	$(MAKE) -C $(LIBFTDIR) fclean
	rm -rf $(NAME) $(LIBNAME) $(TESTNAME)

re: fclean lib

run: $(LIBNAME)
	$(CC) $(CFLAGS) -g $(TESTFILE) -L. -l$(NAME) -lreadline -o $(TESTNAME)
	./$(TESTNAME)

$(LIBNAME): $(OBJ)
	$(MAKE) -C $(HASHTABLEDIR)
	$(MAKE) -C $(LIBFTDIR)
	ar -x $(HASHTABLEDIR)/lib$(HASHTABLE).a
	ar -x $(LIBFTDIR)/lib$(LIBFT).a
	mv *.o $(OBJDIR)
	ar -rc $(LIBNAME) $(OBJDIR)/*.o
	ranlib $(LIBNAME)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	mkdir -p $(OBJDIR)
	$(CC) -c -g $< -o $@
