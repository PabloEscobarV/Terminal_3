/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_operation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 01:01:28 by Pablo Escob       #+#    #+#             */
/*   Updated: 2025/02/27 21:00:21 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/netdata.h"
#include "../../libft/libft.h"

t_uchar	set_operation(t_cchar *data, t_uchar operation, t_argv *argvt)
{
	t_uchar	is_operation;

	is_operation = 0;
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
			is_operation = 1;
	}
	return (is_operation);
}
