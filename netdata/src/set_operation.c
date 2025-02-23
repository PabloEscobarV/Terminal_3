/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_operation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 01:01:28 by Pablo Escob       #+#    #+#             */
/*   Updated: 2025/02/23 01:02:14 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/netdata.h"
#include "../../libft/libft.h"

static t_uchar	_set_file(t_cchar *data, t_uchar operation, t_argv *argvt)
{
	t_uchar	is_seted;

	is_seted = 1;
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
			is_seted = 0;
	}
	return (is_seted);
}

static t_uchar	_set_arg_param(t_cchar *data, t_argv *argvt)
{
	
}

void	_set_operation(t_cchar *data, t_uchar operation, t_argv *argvt)
{
	if (_set_file(data, operation, argvt))
		return ;
	
}