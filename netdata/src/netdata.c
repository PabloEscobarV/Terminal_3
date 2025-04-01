/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   netdata.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 23:32:36 by Pablo Escob       #+#    #+#             */
/*   Updated: 2025/04/01 21:34:45 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/netdata.h"
#include "../hdrs/netdata_service.h"
#include "../../splitter_2/hdrs/splitter.h"
#include "../../libft/libft.h"
#include "../../get_app_path/hdrs/get_app_path.h"
#include <stdio.h>

static t_uchar	set_file(t_cchar *file, int operation, t_argv *argvt)
{
	switch (operation)
	{
	case E_OPER_APP_OUTFILE:
		argvt->out_append = E_TRUE;
		if (argvt->out_file)
			free((void *)argvt->out_file);
		argvt->out_file = ft_strdup(file);
		break ;
	case E_OPER_OUTFILE:
		if (argvt->out_file)
			free((void *)argvt->out_file);
		argvt->out_file = ft_strdup(file);
		break ;
	case E_OPER_INFILE:
		if (argvt->in_file)
			free((void *)argvt->in_file);
		argvt->in_file = ft_strdup(file);
		break ;
	default:
		operation = E_FALSE;
		break;
	}
	return (operation);
}

static inline t_args *get_args(t_llist *data)
{
	return ((t_args *)(data->data));
}

static inline	t_args	*get_next_args(t_llist *data)
{
	return ((t_args *)(data->next->data));
}

static t_llist	*get_data(t_llist **data, t_argv *argvt)
{
	t_llist	*argv_llist;

	argv_llist = NULL;
	while (*data && argvt->operation < 0)
	{
		if (argvt->operation != -2 && get_args(*data)->data && get_args(*data)->data[0])
			llistadd_back(&argv_llist, llistnewnode(ft_strdup(get_args(*data)->data)));
		argvt->operation = get_args(*data)->operation;
		*data = (*data)->next;
		if (!(*data))
			break ;
		if (set_file(get_args(*data)->data, argvt->operation, argvt))
			argvt->operation = -2;
	}
	return (argv_llist);
}

static t_cchar	**get_strv_from_llst(t_llist *llst)
{
	t_uint		llist_size;
	t_uint		i;
	t_cchar		**strv;

	llist_size = llistsize(llst);
	strv = malloc((llist_size + 1) * sizeof(char *));
	if (!strv)
	{
		ft_perror("ERROR!!! Bad mammory allocation");
		exit(-1);
	}
	strv[llist_size] = NULL;
	i = 0;
	while (llst && i < llist_size)
	{
		strv[i] = llst->data;
		++i;
		llst = llst->next;
	}
	return (strv);
}

static t_argv	*get_argvt(t_llist **data)
{
	t_llist	*argv_llist;
	t_argv	*argvt;

	argvt = crt_argvt();
	argv_llist = get_data(data, argvt);
	if (argv_llist)
	{
		argvt->argv = (t_cchar **)get_strv_from_llst(argv_llist);
		argvt->app_path = get_app_path(argvt->argv[0], getenv(PATH));
		llistclear(&argv_llist, ft_void);
	}
	return (argvt);
}

t_llist	*netdata(t_llist *data)
{
	t_argv	*argvt;
	t_llist	*argvt_llist;

	if (!data)
		return (NULL);
	argvt_llist = NULL;
	while (data)
	{
		argvt = get_argvt(&data);
		if (argvt)
			llistadd_back(&argvt_llist, llistnewnode(argvt));
	}
	return (argvt_llist);
}

// static t_cchar	*_remove_spaces_from_data(t_cchar *data)
// {
// 	int	end;

// 	while (*data && ft_isspace(*data))
// 		++data;
// 	end = ft_strlen(data) - 1;
// 	while (data + end != data && ft_isspace(data[end]))
// 		--end;
// 	if (data + end == data)
// 		return (NULL);
// 	return (ft_strldup(data, end + 1));
// }

// static t_uint	_get_end_file_name(t_cchar *data)
// {
// 	t_uint	i;
// 	char		tmp;

// 	i = ft_skip_spaces(data + 1) - data;
// 	if (ft_isdigit(data[i]))
// 	{
// 		while (data[i] && ft_isdigit(data[i]))
// 			++i;
// 		return (i);
// 	}
// 	if (data[i] == '\'' || data[i] == '\"')
// 	{
// 		tmp = data[i];
// 		++i;
// 		while (data[i] && data[i] != tmp && !ft_escape(data, i))
// 			++i;
// 		return (i);
// 	}
// 	while (data[i] && !ft_isspace(data[i]))
// 		++i;
// 	return (i);
// }

// t_uchar	set_file_oper(t_cchar *data, t_uchar operation, t_argv *argvt)
// {
// 	switch (operation)
// 	{
// 	case E_OPER_APP_OUTFILE:
// 			argvt->out_append = E_OPER_APP_OUTFILE;
// 			argvt->out_file = ft_strdup(data);
// 		break ;
// 	case E_OPER_INFILE:
// 			argvt->in_file = ft_strdup(data);
// 		break ;
// 	case E_OPER_OUTFILE:
// 			argvt->out_file = ft_strdup(data);
// 		break ;
// 	default:
// 		operation = E_OPER_SIZE;
// 		break ;
// 	}
// 	return (operation);
// }

// static t_uint _set_in_out_file(t_cchar *args, t_cchar **data, t_cchar **operations, t_argv *argvt)
// {
// 	t_uint	i;
// 	t_uint	size;
// 	t_crd		crd;
// 	t_uchar	oper_code;

// 	crd.i = 0;
// 	crd.size = ft_strlen(args);
// 	size = 0;
// 	i = 0;
// 	while (data[i])
// 	{
// 		oper_code = get_operation_code(args, &crd, operations) + E_OPER_APP_OUTFILE;
// 		crd.i += ft_strlen(data[i]);
// 		if (set_file_oper(data[i], oper_code, argvt) != E_OPER_SIZE)
// 		{
// 			((char **)data)[i][0] = 0;
// 			++size;
// 		}
// 		++i;
// 	}
// 	return (i - size);
// }

// static void	_set_argv_data(t_cchar **data, t_uint size, t_argv *argvt)
// {
// 	t_uint	i;

// 	argvt->argv = malloc((size + 1) * sizeof(char *));
// 	if (!(argvt->argv))
// 	{
// 		ft_perror("ERROR!!! Memory alocation\n");
// 		exit(-1);
// 	}
// 	i = 0;
// 	while (*data)
// 	{
// 		if (**data)
// 		{
// 			argvt->argv[i] = ft_strdup(*data);
// 			++i;
// 		}
// 		++data;
// 	}
// 	argvt->argv[i] = NULL;
// 	argvt->app_path = get_app_path(argvt->argv[0], getenv(PATH));
// }

// t_argv	*_set_argvt(t_cchar *data, t_cchar **operations)
// {
// 	t_uint	size;
// 	t_argv	*argvt;
// 	t_cchar	**argv;

// 	data = ft_skip_spaces(data);
// 	if (!(*data))
// 		return (NULL);
// 	argvt = crt_argvt();
// 	argv = (t_cchar **)splitter(data, operations);
// 	size = _set_in_out_file(data, argv, operations, argvt);
// 	_set_argv_data(argv, size, argvt);
// 	ft_free_d((void **)argv);
// 	return (argvt);
// }

// t_llist	*_set_argv_llist(t_cchar *args, t_cchar **data, t_cchar **operations)
// {
// 	t_crd		crd;
// 	t_llist	*argv_llist;
// 	t_argv	*argvt;
// 	t_cchar	**l_operations;

// 	crd.i = 0;
// 	crd.size = ft_strlen(args);
// 	l_operations = (t_cchar **)ft_split(NDS_SPLITERS, NDS_SPLT);
// 	argv_llist = NULL;
// 	while (*data)
// 	{
// 		argvt = _set_argvt(*data, l_operations);
// 		if (argvt)
// 		{
// 			crd.i += ft_strlen(*data);
// 			printf("TEST:\targs:\t|%s|\n", args + crd.i);
// 			argvt->operation = get_operation_code(args, &crd, operations);
// 			llistadd_back(&argv_llist, llistnewnode((void *)argvt));
// 		}
// 		++data;
// 	}
// 	return (argv_llist);
// }

// t_llist	*netdata(t_cchar *args, t_cchar **operations, t_cchar **data)
// {
// 	t_llist	*argv_llist;

// 	if (!data || !(*data) || !args)
// 		return (NULL);
// 	argv_llist = _set_argv_llist(args, data, operations);
// 	return (argv_llist);
// }
