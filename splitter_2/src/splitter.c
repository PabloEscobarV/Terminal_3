/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   splitter.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 13:39:44 by Pablo Escob       #+#    #+#             */
/*   Updated: 2025/03/19 01:49:28 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/splitter.h"
#include "../hdrs/splitter_srvs.h"
#include "../../libft/libft.h"
#include "../../E_Codes/e_codes.h"
#include <stdlib.h>
#include <stdio.h>

static int	get_oper_crd_qts(t_cchar *str, t_crd *crd, t_cchar **operations)
{
	char	*tmp;

	tmp = ft_strchr(SPLT_QUETS, str[crd->i]);
	if (!tmp)
		return (E_OK);
	while (crd->i < crd->size)
	{
		if (str[crd->i] == *tmp && ft_escape_ch(str, crd->i))
			break ;
		++crd->i;
	}
	return (E_KO);
}

static int	get_oper_crd(t_cchar *str, t_crd *crd, t_cchar **operations)
{
	int	oper_code;

	oper_code = E_ERR;
	while (crd->i < crd->size)
	{
		if (ft_strchr(SPLT_QUETS, str[crd->i]))
		{
			--crd->i;
			break ;
		}
		oper_code = ft_cmp_strv_crd(str + crd->i, operations);
		if (oper_code >= 0)
		{
			if (esc_ch_filter(str, crd, SPLT_ESC_CH))
				break ;
			crd->i += ft_strlen(operations[oper_code]) - 1;
		}
		++crd->i;
	}
	return (oper_code);
}

static t_cchar	*get_clean_data(t_cchar *str, int start, t_crd *crd)
{
	int			end;

	end = ft_skip_spaces_end(str, crd->size) - str;
	if (ft_isspace(str[end]))
		return (NULL);
	start = ft_skip_spaces(str + start) - str;
	return (ft_strldup(str + start, end - start + 1));
}

t_args	*crt_t_args(t_cchar *data, t_uchar operation)
{
	t_args	*argst;

	if (!data)
		return (NULL);
	argst = malloc(sizeof(t_args));
	if (!argst)
	{
		ft_perror("ERROR!!! Memory allocations");
		exit(-1);
	}
	argst->data = data;
	argst->operation = operation;
	return (argst);
}

static t_args	*get_args_qts(t_cchar *str, t_crd *crd, t_cchar **operations)
{
	int			start;
	t_args	*argst;

	start = crd->i;
	if (!get_oper_crd_qts(str, crd, operations))
		return (NULL);
	argst = crt_t_args(ft_strldup(str + start, crd->i - start + 1), -1);
	return (argst);
}

static t_args	*get_args_data(t_cchar *str, t_crd *crd, t_cchar **operations)
{
	int			start;
	int			oper_code;
	t_args	*argst;

	start = crd->i;
	oper_code = get_oper_crd(str, crd, operations);
	argst = crt_t_args(get_clean_data(str, start, crd->i), oper_code);
	if (oper_code >= 0)
		crd->i += ft_strlen(operations[oper_code]) - 1;
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
		++crd->i;
	}
	return (llst);
}


static int	get_str_crd(t_cchar *str, t_crd *crd, t_cchar **operation)
{
	int	i;
	t_cchar	*tmp;

	while (crd->i < crd->size)
	{
		skip_qts(str, crd);
		tmp = ft_cmp_strv(str + crd->i, operation);
		if (tmp)
		{
			if (esc_ch_filter(str, crd, SPLT_ESC_CH))
				break ;
			i = ft_strlen(tmp) - 1;
			if (i > 0)
				crd->i += i;
		}
		++crd->i;
	}
	return (ft_strlen(tmp));
}

static char	*get_str(t_cchar *str, t_crd *crd, t_cchar **operation)
{
	int		i;
	int		tmp;
	char	*result;

	tmp = crd->i;
	i = get_str_crd(str, crd, operation);
	if (tmp < crd->i)
		result = ft_strldup(str + tmp, crd->i - tmp);
	else
		result = NULL;
	crd->i += i;
	return (result);
}

static t_llist	*get_list(t_cchar *str, t_crd *crd, t_cchar **operation)
{
	char	*tmp;
	t_llist	*llst;

	llst = NULL;
	while (crd->i < crd->size)
	{
		tmp = get_str(str, crd, operation);
		if (tmp)
			llistadd_back(&llst, llistnewnode(tmp));
	}
	return (llst);
}

static char	**get_strv_from_llst(t_llist *llst)
{
	int		sizev;
	char	**strv;

	sizev = llistsize(llst);
	if (!sizev)
		return (NULL);
	strv = malloc((sizev + 1) * sizeof(char *));
	if (!strv)
	{
		ft_perror("ERROR!!! Bad mammory allocation");
		exit(-1);
	}
	strv[sizev] = NULL;
	sizev = 0;
	while (llst)
	{
		strv[sizev] = llst->data;
		++sizev;
		llst = llst->next;
	}
	return (strv);
}

char	**splitter(t_cchar *str, t_cchar **operation)
{

}
