/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 20:14:16 by Pablo Escob       #+#    #+#             */
/*   Updated: 2025/06/16 21:33:32 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/terminal.h"

#include "../../netdata/hdrs/netdata.h"
#include "../../str_handler/hdrs/str_handler.h"
#include "../../libft/libft.h"
#include "../hdrs/pipex.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <readline/readline.h>

static int**	create_pipes(int pipe_count)
{
	int	**pipefds;

	if (pipe_count < 1)
		return (NULL);
	pipefds = malloc((pipe_count + 1) * sizeof(int *));
	if (!pipefds)
	{
		ft_perror("ERROR!!! MALLOC: Try to create pipe");
		exit(-1);
	}
	pipefds[pipe_count] = NULL;
	while (pipe_count)
	{
		--pipe_count;
		pipefds[pipe_count] = malloc(2 * sizeof(int));
		if (!pipefds[pipe_count])
		{
			ft_perror("ERROR!!! MALLOC: Try to create pipe");
			exit(-1);
		}
		if (pipe(pipe_count) < 0)
		{
			ft_perror("ERROR!!! in atemt to open pipe");
			return (NULL);
		}
	}
	return (pipefds);
}

static void	set_pipes(int **pipefds, t_llist *argvll)
{
	if (!get_argv(argvll)->in_file)
	{
		close(pipefds[0][0]);
		pipefds[0][0] = PE_NO_PIPE;
	}
}

static int *create_pid(int size)
{
	int *pid;

	pid = malloc(size * sizeof(int));
	return (pid);
}

void	fork_process(t_llist *argvll, t_cchar **envp)
{
	int	i;
	int	pipe_count;
	int **pipefds;
	int	*pid;

	pipe_count = llistsize(argvll);
	pipefds = create_pipes(pipe_count - 1);
	pid = create_pid(pipe_count);
	set_pipes(pipefds, argvll);
	i = 0;
	while (argvll->next)
	{
		pid[i] = pipex(get_argv(argvll), envp, pipefds[i]);
		pid[i + 1] = pipex(get_argv(argvll->next), envp, pipefds[i]);
		argvll = argvll->next->next;
		i += 2;
	}
	pid[i] = pipex(get_argv(argvll), envp, pipefds[i - 1]);
}

static inline int	pipex_runner(t_argv *argvt, t_cchar **envp, int *pipefd)
{
	return (pipex(argvt->app_path, argvt->argv, envp, pipefd));
}

int	argv_llist_handler(t_llist *argvll, t_cchar	**envp)
{
	int	exit_status;
	int	pipefd[2];

	set_pipefd(&pipefd, argvll->data);
	exit_status = pipex_runner(argvll->data, envp, &pipefd);
	argvll = argvll->next;
	while (argvll)
	{

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