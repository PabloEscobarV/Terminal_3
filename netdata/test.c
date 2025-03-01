/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 18:59:02 by Pablo Escob       #+#    #+#             */
/*   Updated: 2025/03/01 19:21:25 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hdrs/netdata.h"
#include "../splitter/hdrs/splitter.h"
#include "../libft/libft.h"
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

void print_arvt(void *data)
{
	t_argv	*argvt = (t_argv *)data;

	printf("HERDOC:\t%d\tOUT_APPEND:\t%d\n", argvt->in_herdoc, argvt->out_append);
	printf("OPERATION CODE:\t%d\n", argvt->operation);
	printf("APPLICTION PATH:\t%s\n", argvt->app_path);
	printf("INPUT FILE:\t%s\n", argvt->in_file);
	printf("OUTPUT FILE:\t%s\n", argvt->out_file);
	printf("ARGV LIST:\n");
	print_matrix(argvt->argv);
}

void handle_in_data(t_cchar *args)
{

}

int main()
{
	char *str = NULL;
	char **result = NULL;
	while (1)
	{
		if (read_data_from_stdi(&str))
				break;
		result = splitter((t_cchar *)str, ND_SPLITTERS, ND_SKIP_PAIR, ND_ESC_CH);
		print_matrix((t_cchar **)result);

		free(str);
		ft_free_d((void **)result);
	}
	free(str);
	return (0);
}