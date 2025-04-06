/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 13:48:20 by Pablo Escob       #+#    #+#             */
/*   Updated: 2025/04/06 16:17:36 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/str_handler.h"

#include "../netdata/hdrs/netdata.h"
#include "../splitter/hdrs/splitter.h"
#include "../libft/libft.h"
#include "../symb_str_delete/hdrs/str_ch_delete.h"
#include "../handle_in_file/hdrs/handle_in_file.h"
#include "../../HashTable/hdrs/hashtable.h"
#include "../../varhandler/hdrs/varhandler.h"
#include <stdio.h>
#include <readline/readline.h>

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

static void	var_insert(t_llist *argv_llist, t_hashtable *hst)
{
	int	i;
	char	*tmp;

	while (argv_llist)
	{
		i = 0;
		while (get_argv(argv_llist)->argv[i])
		{
			if (get_argv(argv_llist)->argv[i][0] == VH_VARSIGNE)
			{
				tmp = hst->get_data(hst, get_argv(argv_llist)->argv[i] + 1);
				free(get_argv(argv_llist)->argv[i]);
				get_argv(argv_llist)->argv[i] = tmp;
			}
			++i;
		}
		argv_llist = argv_llist->next;
	}
}

t_llist	*str_handler(t_cchar *str, t_hashtable *hst)
{
	t_llist	*args_llist;
	t_llist	*argv_llist;
	t_cchar	**operations;

	operations = ft_split(ND_OPERATIONS, ND_SPACE);
	args_llist = splitter(str, operations);
	var_handler(args_llist, hst);
	argv_llist = netdata(args_llist);
	var_insert(argv_llist, hst);
	
}