/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 13:48:20 by Pablo Escob       #+#    #+#             */
/*   Updated: 2025/04/07 22:34:35 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/str_handler.h"

#include "../../netdata/hdrs/netdata.h"
#include "../../splitter/hdrs/splitter.h"
#include "../../libft/libft.h"
#include "../../str_ch_delete/hdrs/str_ch_delete.h"
#include "../../handle_in_file/hdrs/handle_in_file.h"
#include "../../HashTable/hdrs/hashtable.h"
#include "../../varhandler/hdrs/varhandler.h"
#include <stdio.h>

static inline	int	is_qts(char	ch)
{
	if (ch == SH_DQTS || ch == SH_SQTS)
		return (E_TRUE);
	return (E_FALSE);
}

static void	var_handler(t_llist	*args_llist, t_hashtable *hst)
{
	while (args_llist)
	{
		if (!is_qts(get_args(args_llist)->data[0])
			&& varhandler(get_args(args_llist)->data, hst))
		{
			free_t_args(args_llist->data);
			args_llist->data = NULL;
		}
		args_llist = args_llist->next;
	}
}

static void	var_insert(const char **str, t_hashtable *hst)
{
	const char	*tmp;

	if (*str[0] == VH_VARSIGNE)
	{
		tmp = hst->get_data(hst, *str + 1);
		if (tmp)
		{
			free((void *)(*str));
			*str = tmp;
		}
	}
}

static void ch_delete(const char **str)
{
	const char	*tmp;

	if (**str == SH_DQTS)
	{
		tmp = str_ch_delete(*str, ND_ESC_CH);
		free((void *)(*str));
		*str = tmp;
	}
}

static void correct_argv_str(t_llist *argv_llist, t_hashtable *hst)
{
	int	i;
	char	*tmp;

	i = 0;
	while (get_argv(argv_llist)->argv[i])
	{
		var_insert(get_argv(argv_llist)->argv + i, hst);
		ch_delete(get_argv(argv_llist)->argv + i);
		++i;
	}
}

static void	correct_argv(t_llist *argv_llist, t_hashtable *hst)
{
	while (argv_llist)
	{
		correct_argv_str(argv_llist, hst);
		argv_llist = argv_llist->next;
	}
}

t_llist	*str_handler(t_cchar *str, t_cchar **operations, t_hashtable *hst)
{
	t_llist	*args_llist;
	t_llist	*argv_llist;

	args_llist = splitter(str, operations);
	var_handler(args_llist, hst);
	argv_llist = netdata(args_llist);
	llistclear(&args_llist, free_t_args);
	correct_argv(argv_llist, hst);
	return (argv_llist);
}
