/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   netdata.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 23:32:36 by Pablo Escob       #+#    #+#             */
/*   Updated: 2025/02/27 21:00:37 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/netdata.h"
#include "../hdrs/netdata_service.h"
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

t_argv	*_set_argvt(const char *args, t_crd *crd, t_cchar *data, t_cchar **operations)
{
	t_uchar	operation;
	t_argv	*argvt;

	argvt = _crt_argvt();
	operation = _get_oper(args, crd, operations);
	if (set_operation(data, operation, argvt))
		set_arg_list(data, argvt);
	return (argvt);
}

t_llist	*_set_argv_llist(t_cchar *args, t_cchar **data, t_cchar **operations)
{
	t_crd	crd;
	t_llist	*argv_llist;
	t_argv	*argvt;

	crd.i = 0;
	crd.size = ft_strlen(args);
	argv_llist = NULL;
	while (*data)
	{
		argvt = _set_argvt(args, &crd, *data, operations);
		llistadd_back(&argv_llist, llistnewnode((void *)argvt));
		++data;
	}
	return (argv_llist);
}

t_llist	*netdata(t_cchar *args, t_cchar **data, t_cchar **operations)
{
	t_llist	*argv_llist;

	while (*data)
	{

		++data;
	}
}
