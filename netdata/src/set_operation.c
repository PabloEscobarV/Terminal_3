/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_operation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 01:01:28 by Pablo Escob       #+#    #+#             */
/*   Updated: 2025/03/01 18:37:57 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/netdata.h"
#include "../../libft/libft.h"
#include "../../get_app_path/hdrs/get_app_path.h"

static void	_set_arg_list(t_cchar *data, t_argv *argvt)
{
	char	*path;

	path = getenv(PATH);
	argvt->argv = splitter(data, " ", ND_SKIP_PAIR, ND_ESC_CH);
	argvt->app_path = get_app_path(argvt->argv[0], path);
	free(path);
}

void	set_operation(t_cchar *data, t_uchar operation, t_argv *argvt)
{
	switch (operation)
	{
	case E_OPER_APP_OUTFILE:
			argvt->out_append = E_OPER_APP_OUTFILE;
			argvt->out_file = data;
		break;
	case E_OPER_HERDOC:
			argvt->in_herdoc = E_OPER_HERDOC;
			argvt->in_file = data;
		break;
	case E_OPER_INFILE:
			argvt->in_file = data;
		break;
	case E_OPER_OUTFILE:
			argvt->out_file = data;
		break;
	default:
			argvt->operation = operation;
			_set_arg_list(data, argvt);
	}
}
