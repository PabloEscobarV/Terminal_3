/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 22:01:48 by Pablo Escob       #+#    #+#             */
/*   Updated: 2025/04/07 22:17:54 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hdrs/str_handler.h"

#include "../netdata/hdrs/netdata.h"
#include "../splitter/hdrs/splitter.h"
#include "../libft/libft.h"
#include "../HashTable/hdrs/hashtable.h"
#include <stdio.h>
#include <readline/readline.h>

static int read_data_from_stdi(char **str)
{
	*str = readline("Pablo Escobar:\t");
	if (!ft_strcmp(*str, "exit"))
			return (1);
	return (0);
}

void print_matrix(const char **strv)
{
	if (!strv)
	{
		printf("NULL POINTER STRV\n");
		return;
	}
	while (*strv)
	{
		printf("|%s|\n", *strv);
		++strv;
	}
}

void print_args(void *data)
{
	t_args	*argst = (t_args *)data;

	printf("OPERATION CODE:\t%d\nDATA:\t|%s|\n-------------\n", argst->operation, argst->data);
}

void print_argvt(void *data)
{
	t_argv	*argvt = (t_argv *)data;

	if (!argvt)
	{
		printf("ARGVT IS NULL!!!\n");
		return ;
	}
	printf("HERDOC:\t%d\tOUT_APPEND:\t%d\n", argvt->in_herdoc, argvt->out_append);
	printf("OPERATION CODE:\t%d\n", argvt->operation);
	printf("APPLICTION PATH:\t%s\n", argvt->app_path);
	printf("INPUT FILE:\t%s\n", argvt->in_file);
	printf("OUTPUT FILE:\t%s\n", argvt->out_file);
	printf("ARGV LIST:\n");
	print_matrix((t_cchar **)argvt->argv);
	printf("================================\n");
}

void handle_in_data(t_cchar *args, t_cchar **operations, t_hashtable *hst)
{
	t_llist	*llist_argvt;

	llist_argvt = str_handler(args, operations, hst);
	llistiter(llist_argvt, print_argvt);
	llistclear(&llist_argvt, free_argvt);
}

int main()
{
	char *str = NULL;
	t_cchar	**operations = (t_cchar **)ft_split(ND_OPERATIONS, ' ');
	t_hashtable *hst = crthashtable(16);

	while (1)
	{
		if (read_data_from_stdi(&str))
				break;
		handle_in_data((t_cchar *)str, operations, hst);
	}
	free(str);
	ft_free_d((void **)operations);
	return (0);
}
