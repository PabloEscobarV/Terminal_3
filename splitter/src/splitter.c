/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   splitter.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 13:39:44 by Pablo Escob       #+#    #+#             */
/*   Updated: 2025/03/23 20:04:55 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/splitter.h"
#include "../hdrs/splitter_srvs.h"
#include "../../libft/libft.h"
#include <stdlib.h>

static int	skip_space_oper(t_cchar *str, t_crd *crd, int operation,
							t_cchar **operations)
{
	if (ft_isspace(str[crd->i]))
	{
		crd->i = ft_skip_spaces(str + crd->i) - str;
		operation = ft_cmp_strv_crd(str + crd->i, operations);
	}
	return (operation);
}

static t_args	*get_args_qts(t_cchar *str, t_crd *crd, t_cchar **operations)
{
	t_uint	start;
	t_uint	end;
	t_args	*argst;

	start = crd->i;
	if (!get_oper_crd_qts(str, crd, operations))
		return (NULL);
	++crd->i;
	end = crd->i - start;
	argst = crt_t_args(ft_strldup(str + start, crd->i - start), -1);
	crd->i = ft_skip_spaces(str + crd->i) - str;
	argst->operation = ft_cmp_strv_crd(str + crd->i, operations);
	if (argst->operation >= 0)
		crd->i += ft_strlen(operations[argst->operation]);
	return (argst);
}

static t_args	*get_args_data(t_cchar *str, t_crd *crd, t_cchar **operations)
{
	t_uint	start;
	t_uint	end;
	int			oper_code;
	t_args	*argst;

	crd->i = ft_skip_spaces(str + crd->i) - str;
	start = crd->i;
	oper_code = get_oper_crd(str, crd, operations);
	end = crd->i - start;
	oper_code = skip_space_oper(str, crd, oper_code, operations);
	argst = crt_t_args(ft_strldup(str + start, end), oper_code);
	if (oper_code >= 0)
		crd->i += ft_strlen(operations[oper_code]);
	return (argst);
}

static t_llist	*get_list(t_cchar *str, t_crd *crd, t_cchar **operations)
{
	t_args	*argst;
	t_llist	*llst;

	llst = NULL;
	while (crd->i < crd->size)
	{
		argst = get_args_qts(str, crd, operations);
		if (!argst)
			argst = get_args_data(str, crd, operations);
		if (argst)
			llistadd_back(&llst, llistnewnode(argst));
	}
	return (llst);
}

t_llist	*splitter(t_cchar *str, t_cchar **operation)
{
	t_crd	crd;

	if (!str || !operation)
		return (NULL);
	crd.i = 0;
	crd.size = ft_strlen(str);
	return (get_list(str, &crd, operation));
}
