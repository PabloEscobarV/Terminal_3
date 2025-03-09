/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_operation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 01:01:28 by Pablo Escob       #+#    #+#             */
/*   Updated: 2025/03/09 16:03:32 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/netdata.h"
#include "../../libft/libft.h"
#include "../../get_app_path/hdrs/get_app_path.h"
#include "../../splitter/hdrs/splitter.h"

#include <stdio.h>

static void print_matrix(const char **strv)
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

static void	_set_app_path(t_argv *argvt, t_cchar *path)
{
	char	tmp;
	int		name_end;

	name_end  = 0;
	while (argvt->argv[0][name_end] && !ft_isspace(argvt->argv[0][name_end]))
		++name_end;
	tmp = argvt->argv[0][name_end];
	((char **)argvt->argv)[0][name_end] = '\0';
	argvt->app_path = get_app_path(argvt->argv[0], path);
	((char **)argvt->argv)[0][name_end] = tmp;
}

static void	_set_arg_list(t_cchar *data, t_argv *argvt)
{
	char	*path;
	t_splitter	splittert;

	splittert.ecs_split = ND_ESC_CH;
	splittert.skip_pair = (t_cchar **)ft_split(ND_SKIP_PAIR, ' ');
	splittert.splt = (t_cchar **)ft_split(" ", '\0');
	path = getenv(PATH);
	argvt->argv = (t_cchar **)splitter(data, &splittert);
	_set_app_path(argvt, path);
	ft_free_d((void **)splittert.skip_pair);
	ft_free_d((void **)splittert.splt);
}

void	set_operation(t_cchar *data, t_uchar operation, t_argv *argvt)
{
	switch (operation)
	{
	case E_OPER_APP_OUTFILE:
			argvt->out_append = E_OPER_APP_OUTFILE;
			argvt->out_file = ft_strdup(data);
		break;
	case E_OPER_HERDOC:
			argvt->in_herdoc = E_OPER_HERDOC;
			argvt->in_file = ft_strdup(data);
		break;
	case E_OPER_INFILE:
			argvt->in_file = ft_strdup(data);
		break;
	case E_OPER_OUTFILE:
			argvt->out_file = ft_strdup(data);
		break;
	default:
			argvt->operation = operation;
			_set_arg_list(data, argvt);
	}
}
