/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   netdata.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 23:32:36 by Pablo Escob       #+#    #+#             */
/*   Updated: 2025/04/06 10:34:28 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/netdata.h"
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

static t_llist	*get_data(t_llist **data, t_argv *argvt)
{
	t_llist	*argv_llist;

	argv_llist = NULL;
	while (*data && argvt->operation < 0)
	{
		if (argvt->operation != E_OPER_NV && get_args(*data)->data && get_args(*data)->data[0])
			llistadd_back(&argv_llist, llistnewnode(ft_strdup(get_args(*data)->data)));
		argvt->operation = get_args(*data)->operation;
		*data = (*data)->next;
		if (!(*data))
			break ;
		if (set_file(get_args(*data)->data, argvt->operation, argvt))
			argvt->operation = E_OPER_NV;
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
