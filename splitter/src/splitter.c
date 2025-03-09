/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   splitter.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 13:39:44 by Pablo Escob       #+#    #+#             */
/*   Updated: 2025/03/09 15:21:48 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/splitter.h"
#include "../hdrs/splitter_srvs.h"
#include "../../libft/libft.h"
#include "../../E_Codes/e_codes.h"
#include <stdlib.h>
#include <stdio.h>

static int	get_str_crd(t_cchar *str, t_crd *crd, t_splitter *splitters)
{
	int	i;
	t_cchar	*tmp;

	while (crd->i < crd->size)
	{
		skip_qts(str, crd, splitters);
		tmp = ft_cmp_strv(str + crd->i, splitters->splt);
		if (tmp)
		{
			if (esc_ch_filter(str, crd, splitters->ecs_split))
				break ;
			i = ft_strlen(tmp) - 1;
			if (i > 0)
				crd->i += i;
		}
		++crd->i;
	}
	return (ft_strlen(tmp));
}

static char	*get_str(t_cchar *str, t_crd *crd, t_splitter *splitters)
{
	int		i;
	int		tmp;
	char	*result;

	tmp = crd->i;
	i = get_str_crd(str, crd, splitters);
	if (tmp < crd->i)
		result = ft_strldup(str + tmp, crd->i - tmp);
	else
		result = NULL;
	crd->i += i;
	return (result);
}

static t_llist	*get_list(t_cchar *str, t_crd *crd, t_splitter *splitters)
{
	char	*tmp;
	t_llist	*llst;

	llst = NULL;
	while (crd->i < crd->size)
	{
		tmp = get_str(str, crd, splitters);
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

char	**splitter(t_cchar *str, t_splitter *splitters)
{
	char		**strv;
	t_llist	*llst;
	t_crd		crd;

	if (!str)
		return (NULL);
	if (!splitters)
		return (transfer_str(str));
	crd.i = 0;
	crd.size = ft_strlen(str);
	llst = get_list(str, &crd, splitters);
	strv = get_strv_from_llst(llst);
	llistclear(&llst, ft_void);
	return (strv);
}
