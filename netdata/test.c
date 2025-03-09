/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 18:59:02 by Pablo Escob       #+#    #+#             */
/*   Updated: 2025/03/09 15:49:19 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hdrs/netdata.h"
#include "../splitter/hdrs/splitter.h"
#include "../libft/libft.h"
#include "../symb_str_delete/hdrs/str_ch_delete.h"
#include "../handle_in_file/hdrs/handle_in_file.h"
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

void print_argvt(void *data)
{
	t_argv	*argvt = (t_argv *)data;

	printf("HERDOC:\t%d\tOUT_APPEND:\t%d\n", argvt->in_herdoc, argvt->out_append);
	printf("OPERATION CODE:\t%d\n", argvt->operation);
	printf("APPLICTION PATH:\t%s\n", argvt->app_path);
	printf("INPUT FILE:\t%s\n", argvt->in_file);
	printf("OUTPUT FILE:\t%s\n", argvt->out_file);
	printf("ARGV LIST:\n");
	print_matrix((t_cchar **)argvt->argv);
	printf("================================\n");
}

void handle_in_data(t_cchar *args)
{
	t_llist	*llist_argvt;
	char	**data;
	t_splitter	*splittert = crt_splitter((t_cchar **)ft_split(ND_SPLITTERS, ' '),
														(t_cchar **)ft_split(ND_SKIP_PAIR, ' '), ND_ESC_CH);

	args = str_ch_delete(args, '\\');
	move_symbol((char *)args, ND_RSRVD_SYMB, '<');
	printf("TEST: AFTER MOVE_SYMOBOL:\t%s\n", args);
	data = splitter(args, splittert);
	print_matrix((t_cchar **)data);
	llist_argvt = netdata(args, splittert->splt, (t_cchar **)data);
	free((void *)args);
	ft_free_d((void **)data);
	llistiter(llist_argvt, print_argvt);
	llistclear(&llist_argvt, free_argvt);
}

int main()
{
	char *str = NULL;

	while (1)
	{
		if (read_data_from_stdi(&str))
				break;
		handle_in_data((t_cchar *)str);
	}
	free(str);
	return (0);
}