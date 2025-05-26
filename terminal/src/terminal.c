/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 20:14:16 by Pablo Escob       #+#    #+#             */
/*   Updated: 2025/05/26 21:47:20 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/terminal.h"

#include "../../netdata/hdrs/netdata.h"
#include "../../str_handler/hdrs/str_handler.h"
#include "../../libft/libft.h"
#include "../../pipex/hdrs/pipex.h"
#include <stdio.h>
#include <unistd.h>
#include <readline/readline.h>

void	command_execute(int operation, int exit_status)
{
	switch (operation)
	{
		case E_OPER_OR:
			
			break;
		case E_OPER_AND:

			break ;
		case E_OPER_EXIT_CODE:

			break ;
		case E_OPER_HERDOC:

			break ;
		case E_OPER_APP_OUTFILE:

			break ;
		case E_OPER_OUTFILE:

			break ;
		case E_OPER_INFILE:

			break ;
		case E_OPER_PIPE:

			break ;
		default:
			break;
	}
}

int	set_pipefd(int *pipefd, t_argv *argvt)
{
	if (argvt->operation != E_OPER_PIPE)
	{
		pipefd[0] = -1;
		pipefd[1] = -1;
		return (E_FALSE);
	}
	if (pipe(pipefd) < 0)
	{
		ft_perror("ERROR!!! in atemt to open pipe");
		return (E_ERR);
	}
	return (E_FALSE);
}

static inline int	pipex_runner(t_argv *argvt, t_cchar **envp, int *pipefd)
{
	return (pipex(argvt->app_path, argvt->argv, envp, pipefd));
}

int	argv_llist_handler(t_llist *argvll, t_cchar	**envp)
{
	int	exit_status;
	int	pipefd[2];

	while (argvll)
	{
		set_pipefd(&pipefd, argvll->data);
		exit_status = pipex_runner(argvll->data, envp, &pipefd);
		
		argvll = argvll->next;
	}
	return (exit_status);
}

static t_cchar	*read_data_with_promt()
{
	char	*str;

	*str = readline(TERMINAL_PROMT);
	if (!ft_strcmp(*str, TERMINAL_EXIT))
	{
		free(str);
		str = NULL;
	}
	return ((t_cchar *)str);
}

void	terminal()
{
	t_cchar	*data;
	t_cchar	**operations;
	t_hashtable *hashtable;
	t_llist	*argvt_llist;

	operations = (t_cchar **)ft_split(ND_OPERATIONS, ' ');
	hashtable = crthashtable(16);
	while (E_TRUE)
	{
		data = read_data_with_promt();
		if (!data)
			break ;
		argvt_llist = str_handler(data, operations, hashtable);

		llistclear(&argvt_llist, free_argvt);
		free(data);
	}
}

int	main()
{

	return (0);
}