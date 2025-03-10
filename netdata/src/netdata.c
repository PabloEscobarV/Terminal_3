/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   netdata.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 23:32:36 by Pablo Escob       #+#    #+#             */
/*   Updated: 2025/03/10 21:14:43 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/netdata.h"
#include "../hdrs/netdata_service.h"
#include "../../splitter/hdrs/splitter.h"
#include "../../libft/libft.h"
#include <stdio.h>

static t_cchar	*_remove_spaces_from_data(t_cchar *data)
{
	int	end;

	while (*data && ft_isspace(*data))
		++data;
	end = ft_strlen(data) - 1;
	while (data + end != data && ft_isspace(data[end]))
		--end;
	if (data + end == data)
		return (NULL);
	return (ft_strldup(data, end + 1));
}

t_argv	*_set_argvt(const char *args, t_crd *crd, t_cchar ***data, t_cchar **operations)
{
	t_uchar	operation;
	t_argv	*argvt;
	t_cchar	*clean_data;


	argvt = crt_argvt();
	while (**data)
	{
		clean_data = _remove_spaces_from_data(**data);
		if (clean_data)
		{
			operation = get_operation_code(args, crd, operations);
			set_operation(clean_data, operation, argvt);
			printf("TEST: in_file:\t%s\n", argvt->in_file);
		}
		++(*data);
		if (argvt->operation < E_OPER_SIZE && !argvt->out_append && !argvt->in_herdoc)
			break ;
	}
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
		argvt = _set_argvt(args, &crd, &data, operations);
		if (argvt)
			llistadd_back(&argv_llist, llistnewnode((void *)argvt));
	}
	return (argv_llist);
}

t_llist	*netdata(t_cchar *args, t_cchar **operations, t_cchar **data)
{
	t_llist	*argv_llist;

	if (!data || !(*data) || !args)
		return (NULL);
	argv_llist = _set_argv_llist(args, data, operations);
	return (argv_llist);
}
