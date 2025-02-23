/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   netdata.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 23:32:36 by Pablo Escob       #+#    #+#             */
/*   Updated: 2025/02/23 01:00:06 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/netdata.h"
#include "../../splitter/hdrs/splitter.h"
#include "../../libft/libft.h"

static t_cchar	*_cmp_str_ret_crd(t_cchar *str, t_cchar **strv)
{
	while (*strv && !ft_strlcmp(str, *strv))
		++strv;
	return (strv);
}

static t_uchar	_get_oper_code(t_cchar *operation, t_cchar **operations)
{
	t_uchar	code;

	while (operation && !ft_strlcmp(operation, operations[code]))
		++code;
	return (code);
}

static t_uchar	_get_oper(t_cchar *args, t_crd *crd, t_cchar **operations)
{
	t_cchar	*operation;

	while (crd->i < crd->size)
	{
		operation = _cmp_str_ret_crd(args + crd->i, operations);
		if (operation)
			break ;
		++crd->i;
	}
	crd->i += ft_strlen(operation);
	return (_get_oper_code(operation, operations));
}

t_argv	*_crt_argvt()
{
	t_argv	*argvt;

	argvt = malloc(sizeof(t_argv));
	if (!argvt)
	{
		ft_perror("ERROR of allocation t_argv");
		exit(-1);
	}
	return (argvt);
}

t_uchar	_set_file(t_cchar *data, t_uchar operation, t_argv *argvt)
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

t_uchar	_set_arg_param(t_cchar *data, t_argv *argvt)
{

}

void	_set_operation(t_cchar *data, t_uchar operation, t_argv *argvt)
{
	if (_set_file(data, operation, argvt))
		return ;
	
}

t_argv	*_set_argvt(const char *args, t_crd *crd, t_cchar **data, t_cchar **operations)
{
	t_uchar	operation;
	int	local_crd;
	t_argv	*argvt;

	argvt = _crt_argvt();
	local_crd = crd->i;
	operation = _get_oper(args, crd, operations);
	if ()
}

t_llist	*netdata(const char *args, const char **data, t_cchar **operations)
{
	
}
